template <typename T>
void MyLib::swap(T &a, T &b)
{
	T c(a);
	a = b;
	b = c;
}

template <typename Iterator>
void MyLib::bubble_sort(Iterator begin, Iterator end)
{
	static_assert(std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value, "The bubble_sort function accepts only random access iterators or raw pointers to an array.\n");
	bool swapped = false;
	do
	{
		swapped = false;
		for (auto iter = begin; iter + 1 != end; iter++)
		{
			if (*iter > *(iter + 1))
			{
				swapped = true;
				MyLib::swap(*iter, *(iter + 1));
			}
		}
	}
	while (swapped);
	return;
}

template <typename Iterator>
void MyLib::selection_sort(Iterator begin, Iterator end)
{
	static_assert(std::is_same<std::random_access_iterator_tag, typename std::iterator_traits<Iterator>::iterator_category>::value, "The selection_sort function accepts only random access iterators or raw pointers to an array.\n");
	auto n = end - begin;
	do
	{
		auto elem = begin;
		for (auto iter = begin + 1; iter != begin + n; iter++)
		{
			if (*iter > *elem)
				elem = iter;
		}
		auto iter = begin + n - 1;
		if (elem != iter)
			MyLib::swap(*elem, *iter);
		n--;
	}
	while (n > 0);
	return;
}
