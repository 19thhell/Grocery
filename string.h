#ifndef MY_STRING_H
#define MY_STRING_H
#include<cstring>
#include<iostream>

namespace MyLib
{
	class string;

	string operator+(string s, const char c_str[]);
	string operator+(const char c_str[], string s);
	string operator+(string s1, const string &s2);

	bool operator==(const string &s, const char c_str[]);
	bool operator==(const char c_str[], const string &s);
	bool operator==(const string &s1, const string &s2);

	bool operator!=(const string &s, const char c_str[]);
	bool operator!=(const char c_str[], const string &s);
	bool operator!=(const string &s1, const string &s2);

	std::istream &operator>>(std::istream &is, string &s);
	std::ostream &operator<<(std::ostream &os, const string &s);

	class string
	{
		private:
			typedef char* iterator;
			typedef const char* const_iterator;
			char* str;
			unsigned int size;
			unsigned int capacity;

		public:
			string();
			string(const char c_str[]);
			string(const string &s);
			~string();

			string& operator=(const char c_str[]);
			string& operator=(const string &s);

			string& operator+=(const char c_str[]);
			string& operator+=(const string &s);

			friend string operator+(string s, const char c_str[]);
			friend string operator+(const char c_str[], string s);
			friend string operator+(string s1, const string &s2);

			friend bool operator==(const string &s, const char c_str[]);
			friend bool operator==(const char c_str[], const string &s);
			friend bool operator==(const string &s1, const string &s2);

			friend bool operator!=(const string &s, const char c_str[]);
			friend bool operator!=(const char c_str[], const string &s);
			friend bool operator!=(const string &s1, const string &s2);

			iterator begin() const;
			iterator end() const;

			const_iterator cbegin() const;
			const_iterator cend() const;

			inline char &operator[](const int index) const { return str[index]; }
			inline const int length() const { return size; }
			inline const char *c_str() const { return str; }
			inline bool empty() const { return size == 0; }

			friend std::istream &operator>>(std::istream &is, string &s);
			friend std::ostream &operator<<(std::ostream &os, const string &s);
	};
}
#endif
