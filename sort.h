#ifndef GROC_SORT_H
#define GROC_SORT_H
#include<iterator>
#include<type_traits>
#include<stack>
#include<vector>
#include<algorithm>

namespace Grocery {
	//Basic accessories
	template <typename T> inline
	void swap(T &a, T &b) {
		if (&a != &b) {
			T temp = a;
			a = b;
			b = temp;
		}
	}

	//Sorting algorithms
	template <typename Iterator>
	void bubble_sort(Iterator begin, Iterator end);

	template <typename Iterator>
	void selection_sort(Iterator begin, Iterator end);

	template <typename Iterator>
	void insertion_sort(Iterator begin, Iterator end);

	template <typename Iterator, typename GetNextK>
	void shell_sort(Iterator begin, Iterator end, GetNextK getNext);

	template <typename Iterator>
	void quick_sort(Iterator begin, Iterator end);
	
	template <typename Iterator>
	void merge_sort(Iterator begin, Iterator end);

	template <typename Iterator>
	void heap_sort(Iterator begin, Iterator end);
//	void bucket_sort(Iterator begin, Iterator end);
}

#include "sort.cpp"
#endif
