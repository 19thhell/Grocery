template <typename Iterator>
void Grocery::bubble_sort(Iterator begin, Iterator end) {
	static_assert(std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value, "The bubble_sort function accepts only random access iterators or raw pointers to an array.\n");
	bool swapped = false;
	do {
		swapped = false;
		for (auto iter = begin; iter + 1 != end; iter++) {
			if (*iter > *(iter + 1)) {
				swapped = true;
				Grocery::swap(*iter, *(iter + 1));
			}
		}
	}
	while (swapped);
	return;
}

template <typename Iterator>
void Grocery::selection_sort(Iterator begin, Iterator end) {
	static_assert(std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value, "The selection_sort function accepts only random access iterators or raw pointers to an array.\n");
	auto n = end - begin;
	do {
		auto elem = begin;
		for (auto iter = begin + 1; iter != begin + n; iter++) {
			if (*iter > *elem)
				elem = iter;
		}
		auto iter = begin + n - 1;
		if (elem != iter)
			Grocery::swap(*elem, *iter);
		n--;
	}
	while (n > 0);
	return;
}

template <typename Iterator>
void Grocery::insertion_sort(Iterator begin, Iterator end) {
	static_assert(std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value, "The insertion_sort function accepts only random access iterators or raw pointers to an array.\n");
	for (auto iter = begin + 1; iter != end; iter++) {
		auto pos = iter;
		auto rec = *pos;
		while (pos != begin && rec < *(pos - 1)) {
			*pos = *(pos - 1);
			pos--;
		}
		*pos = rec;
	}
	return;
}

template <typename Iterator, typename GetNextK>
void Grocery::shell_sort(Iterator begin, Iterator end, GetNextK getNext) {
	static_assert(std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value, "The shell_sort function accepts only random access iterators or raw pointers to an array.\n");
	auto n = end - begin;
	auto k = getNext(n);
	while (k >= 1) {
		for (auto iter = begin + k; end - iter >= k; iter += k) {
			auto pos = iter;
			auto rec = *pos;
			while (pos - begin >= k && rec < *(pos - k)) {
				*pos = *(pos - k);
				pos -= k;
			}
			*pos = rec;
		}
		k = getNext(k);
	}
	return;
}

template <typename Iterator> static
auto partition(Iterator begin, Iterator end) -> decltype(end - begin) {
	Iterator pivot = begin + (end - begin) / 2;
	auto pivotVal = *pivot;
	decltype(end - begin) distL = 1, distR = end - begin - 1;
	Grocery::swap(*begin, *pivot);
	while (distL <= distR) {
		while (*(begin + distL) < pivotVal)
			distL++;
		while (*(begin + distR) > pivotVal)
			distR--;
		if (distL <= distR) {
			Grocery::swap(*(begin + distL), *(begin + distR));
			distL++;
			distR--;
		}
	}
	Grocery::swap(*begin, *(begin + distR));
	return distR;
}

template <typename Iterator>
void Grocery::quick_sort(Iterator begin, Iterator end) {
	static_assert(std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value, "The quick_sort function accepts only random access iterators or raw pointers to an array.\n");
	const unsigned int THRESHOLD = 8;
	if (begin == end)
		return;
	using Range = std::pair<Iterator, Iterator>;
	std::stack<Range> stk;
	stk.push(Range(begin, end));
	while (!stk.empty()) {
		auto nextRange = stk.top();
		stk.pop();
		auto left = nextRange.first, right = nextRange.second;
		while (right - left > 1) {
			if (right - left <= THRESHOLD) {
				Grocery::insertion_sort(left, right);
				break;
			}
			decltype(right - left) pivot = partition(left, right);
			if (pivot < right - left - pivot) {
				stk.push(Range(left + pivot + 1, right));
				right = left + pivot;
			} else {
				stk.push(Range(left, left + pivot));
				left = left + pivot + 1;
			}
		}
	}
}

template <typename Iterator> static
void merge(Iterator begin, Iterator mid, Iterator end) {
	using T = typename std::remove_reference<decltype(*begin)>::type;
	size_t size = end - begin;
	std::vector<T> aux(size);
	for (size_t i = 0; i < size; ++i) {
		aux[i] = *(begin + i);
	}
	size_t left = 0, right = mid - begin, mid_idx = mid - begin;
	for (size_t i = 0; i < size; ++i) {
		if (left >= mid_idx) {
			*(begin + i) = aux[right++];
		} else if (right >= size) {
			*(begin + i) = aux[left++];
		} else if (aux[right] < aux[left]) {
			*(begin + i) = aux[right++];
		} else {
			*(begin + i) = aux[left++];
		}
	}
}

template <typename Iterator>
void Grocery::merge_sort(Iterator begin, Iterator end) {
	static_assert(std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value, "The merge_sort function accepts only random access iterators or raw pointers to an array.\n");
	size_t size = end - begin;
	if (size <= 7) {
		insertion_sort(begin, end);
		return;
	}
	for (size_t sub_size = 1; sub_size < size; sub_size *= 2) {
		for (size_t offset = 0; offset < size - sub_size; offset += sub_size * 2) {
			size_t mid = offset + sub_size;
			if (*(begin + mid - 1) <= *(begin + mid)) {
				continue;
			}
			merge(begin + offset, begin + mid, begin + std::min(offset + sub_size * 2, size));
		}
	}
}

template <typename Iterator> static
void sink(Iterator begin, Iterator end, size_t index) {
	size_t size = end - begin;
	while (index * 2 + 1 < size) {
		size_t child = index * 2 + 1;
		if (child < size - 1 && *(begin + child) < *(begin + child + 1)) {
			++child;
		}
		if (!(*(begin + index) < *(begin + child))) {
			break;
		}
		Grocery::swap(*(begin + index), *(begin + child));
		index = child;
	}
}

template <typename Iterator> static
void heapify(Iterator begin, Iterator end) {
	size_t index = end - begin - 1;
	size_t size = index + 1;
	if (index % 2 == 0 && index > 0) {
		--index;
	}
	while (true) {
		size_t parent = (index - 1) / 2;
		size_t child = index;
		if (index < size - 1 && *(begin + index) < *(begin + index + 1)) {
			++child;
		}
		if (*(begin + parent) < *(begin + child)) {
			sink(begin, end, parent);
		}
		if (index > 1) {
			index -= 2;
		} else {
			break;
		}
	}
}

template <typename Iterator>
void Grocery::heap_sort(Iterator begin, Iterator end) {
	static_assert(std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value, "The heap_sort function accepts only random access iterators or raw pointers to an array.\n");
	heapify(begin, end);
	while (end - begin > 1) {
		--end;
		Grocery::swap(*begin, *end);
		heapify(begin, end);
	}
}
