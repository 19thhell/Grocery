#ifndef GROC_ALGORITHM_H
#define GROC_ALGORITHM_H
#include<iterator>
#include<type_traits>
#include<stack>

namespace Grocery
{
	template <typename T>
	void swap(T &a, T &b);

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
//	void merge_sort(Iterator begin, Iterator end);
//	void heap_sort(Iterator begin, Iterator end);
//	void bucket_sort(Iterator begin, Iterator end);
}

#include "algorithm.cpp"
#endif
