#ifndef MY_ALGORITHM_H
#define MY_ALGORITHM_H
#include<iterator>
#include<type_traits>

namespace MyLib
{
	template <typename T>
	void swap(T &a, T &b);

	template <typename Iterator>
	void bubble_sort(Iterator begin, Iterator end);

	template <typename Iterator>
	void selection_sort(Iterator begin, Iterator end);
//	void insertion_sort(Iterator begin, Iterator end);
//	void shell_sort(Iterator begin, Iterator end);
//	void quick_sort(Iterator begin, Iterator end);
//	void merge_sort(Iterator begin, Iterator end);
//	void heap_sort(Iterator begin, Iterator end);
//	void bucket_sort(Iterator begin, Iterator end);
}

#include "algorithm.cpp"
#endif
