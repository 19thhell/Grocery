#ifndef GROC_ALGORITHM_H
#define GROC_ALGORITHM_H
#include<iterator>
#include<type_traits>
#include<stack>
#include<vector>
#include<algorithm>

namespace Grocery
{
	//Basic accessories
	template <typename T> inline
	void swap(T &a, T &b)
	{
		if (&a != &b)
		{
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
//	void heap_sort(Iterator begin, Iterator end);
//	void bucket_sort(Iterator begin, Iterator end);
}

#include "algorithm.cpp"
#endif
