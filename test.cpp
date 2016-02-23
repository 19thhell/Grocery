//#define NDEBUG
#include "primer.h"
#include "string.h"
#include "sort.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>
using namespace std;

void test_str_blob();
void test_string();
void test_sort();

int main() {
	srand(time(0));
	cout << "Start testing module:\n==============================\n";
	test_str_blob();
	test_string();
	test_sort();
	cout << "All tests passed.\n";
	return 0;
}

void test_str_blob() {
	cout << "Testing StrBlob...\n------------------------------\n";
	Grocery::StrBlob b1;
	{
		Grocery::StrBlob b2 = {"a", "b", "c"};
		b1 = b2;
		b2.push_back("d");
	}
	assert(b1.size() == 4);
	cout << "Shared pointer tests finished.\n";
	cout << "==============================\n";
}

void test_string() {
	cout << "Testing string...\n------------------------------\n";
	Grocery::string s1;
	Grocery::string s2("test");
	Grocery::string s3(s1);
	cout << "Constructors tests finished.\n";
	s1 = "test";
	assert(s1 == "test");
	s3 = s2;
	assert(s3 == s2);
	s2 += "another";
	assert(s3 != s2);
	Grocery::string s4 = s1 + s2;
	assert(s4 == "testtestanother");
	Grocery::string s5 = "123";
	s4 = s5 + s4;
	s2 = "123" + s1;
	s2 += "abc";
	assert(s2 == "123testabc");
	s4[0] = 'a';
	assert(s4 == "a23testtestanother");
	cout << "Operators tests finished.\n";
	auto p = s4.begin(), q = s4.end();
	*p = 'b';
	for (; p != q; p++);
	assert(p == q);
	q = s4.begin();
	assert(s4 == "b23testtestanother");
	assert(p == s4.end());
	assert(q != s4.end());
	cout << "Iterators tests finished.\n";
	Grocery::string s6("finished.\n");
	Grocery::string s7;
	s6 = "Iostream " + s1 + "s " + s6;
	stringstream ss;
	ss << s6;
	ss >> s7;
	assert(s7 == "Iostream");
	ss >> s7;
	assert(s7 == "tests");
	cout << s6;
	auto sz = s7.length();
	assert(sz == 5); 
	auto emp = s7.empty();
	assert(emp == false);
	cout << "Functions tests finished.\n";
	cout << "Destructor test finished.\n";
	cout << "==============================\n";
}

void test_sort() {
	cout << "Testing sort...\n------------------------------\n";
	vector<int> ans;
	for (int i = 0; i < 15; i++)
		ans.push_back(i);
	vector<int> init = ans;
	random_shuffle(init.begin(), init.end());
//	vector<int> ans{0, 1, 2, 4, 5, 7, 8, 9};
//	vector<int> ans{0, 1, 2, 3, 4, 5, 6, 7};
//	vector<int> init{0, 2, 4, 6, 1, 3, 5, 7};
	vector<int> v1 = init;
	Grocery::bubble_sort(v1.begin(), v1.end());
	assert(v1 == ans);
	cout << "BubbleSort test finished.\n";
	vector<int> v2 = init;
	Grocery::selection_sort(v2.begin(), v2.end());
	assert(v2 == ans);
	cout << "SelectionSort test finished.\n";
	vector<int> v3 = init;
	Grocery::insertion_sort(v3.begin(), v3.end());
	assert(v3 == ans);
	cout << "InsertionSort test finished.\n";
	struct wrap {
		static unsigned int getNext(unsigned int k) {
			unsigned int bit = 1;
			while ((bit << 1) < k)
				bit <<= 1;
			return bit - 1;
		};
	};
	vector<int> v4 = init;
	Grocery::shell_sort(v4.begin(), v4.end(), wrap::getNext);
	assert(v4 == ans);
	cout << "ShellSort test finished.\n";
	vector<int> v5 = init;
	Grocery::quick_sort(v5.begin(), v5.end());
	assert(v5 == ans);
	cout << "QuickSort test finished.\n";
	vector<int> v6 = init;
	Grocery::merge_sort(v6.begin(), v6.end());
	assert(v6 == ans);
	cout << "MergeSort test finished.\n";
	vector<int> v7 = init;
	Grocery::heap_sort(v7.begin(), v7.end());
	assert(v7 == ans);
	cout << "HeapSort test finished.\n";
	cout << "==============================\n";
}
