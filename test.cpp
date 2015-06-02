//#define NDEBUG
#include"string.h"
#include"algorithm.h"
#include<cassert>
#include<iostream>
#include<sstream>
#include<vector>
#include<list>
using namespace std;

void test_string();
void test_sort();

int main()
{
	cout << "Start testing module:\n==============================\n";
	test_string();
	test_sort();
	cout << "All tests passed.\n";
	return 0;
}

void test_string()
{
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

void test_sort()
{
	cout << "Testing sort...\n------------------------------\n";
	vector<int> ans{1,1,3,4,5};
	vector<int> v1{1,3,1,5,4};
	Grocery::bubble_sort(v1.begin(), v1.end());
	assert(v1 == ans);
	cout << "BubbleSort test finished.\n";
	vector<int> v2{1,3,1,5,4};
	Grocery::selection_sort(v2.begin(), v2.end());
	assert(v2 == ans);
	cout << "SelectionSort test finished.\n";
	vector<int> v3{1,3,1,5,4};
	Grocery::insertion_sort(v3.begin(), v3.end());
	assert(v3 == ans);
	cout << "InsertionSort test finished.\n";
	cout << "==============================\n";
}
