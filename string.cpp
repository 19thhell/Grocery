#include"string.h"

Grocery::string::string() : size(0), capacity(0)
{
	str = new char[1];
	str[size] = '\0';
}

Grocery::string::string(const char c_str[])
{
	size = strlen(c_str);
	capacity = size;
	str = new char[size + 1];
	for (decltype(size) i = 0; i < size; i++)
	{
		str[i] = c_str[i];
	}
	str[size] = '\0';
}

Grocery::string::string(const Grocery::string &s) : size(s.size), capacity(s.size)
{
	str = new char[size + 1];
	for (decltype(size) i = 0; i < size; i++)
	{
		str[i] = s.str[i];
	}
	str[size] = '\0';
}

Grocery::string::~string()
{
	delete[] str;
}

Grocery::string &Grocery::string::operator=(const char c_str[])
{
	auto c_size = strlen(c_str);
	if (size < c_size)
	{
		delete[] str;
		str = new char[c_size + 1];
		capacity = c_size;
	}
	size = c_size;
	strncpy(str, c_str, size);
	str[size] = '\0';
	return *this;
}

Grocery::string &Grocery::string::operator=(const Grocery::string &s)
{
	auto s_size = s.size;
	if (size < s_size)
	{
		delete[] str;
		str = new char[s_size + 1];
		capacity = s_size;
	}
	size = s_size;
	strncpy(str, s.str, size);
	str[size] = '\0';
	return *this;
}

Grocery::string &Grocery::string::operator+=(const char c_str[])
{
	auto c_size = strlen(c_str);
	if (c_size == 0)
		return *this;
	if (size + c_size > capacity)
	{
		char *newstr = new char[size + c_size + 1];
		strncpy(newstr, str, size);
		strncpy(newstr + size, c_str, c_size);
		newstr[size + c_size] = '\0';
		delete[] str;
		str = newstr;
	}
	else
	{
		strncpy(str + size, c_str, c_size);
		str[size + c_size] = '\0';
	}
	size += c_size;
	capacity = size;
	return *this;
}

Grocery::string &Grocery::string::operator+=(const Grocery::string &s)
{
	auto s_size = s.size;
	if (s.size == 0)
		return *this;
	if (size + s_size > capacity)
	{
		char *newstr = new char[size + s_size + 1];
		strncpy(newstr, str, size);
		strncpy(newstr + size, s.str, s_size);
		newstr[size + s_size] = '\0';
		delete[] str;
		str = newstr;
	}
	else
	{
		strncpy(str + size, s.str, s_size);
		str[size + s_size] = '\0';
	}
	size += s_size;
	capacity = size;
	return *this;
}

Grocery::string Grocery::operator+(Grocery::string s, const char c_str[])
{
	return s += c_str;
}

Grocery::string Grocery::operator+(const char c_str[], Grocery::string s)
{
	auto c_size = strlen(c_str);
	if (c_size == 0)
		return s;
	char *newstr = new char[s.size + c_size + 1];
	strncpy(newstr, c_str, c_size);
	strncpy(newstr + c_size, s.str, s.size);
	s.size += c_size;
	s.capacity = s.size;
	newstr[s.size] = '\0';
	s.str = newstr;
	return s;
}

Grocery::string Grocery::operator+(Grocery::string s1, const Grocery::string &s2)
{
	s1 += s2;
	return s1;
}

bool Grocery::operator==(const Grocery::string &s, const char c_str[])
{
	return strcmp(s.str, c_str) == 0;
}

bool Grocery::operator==(const char c_str[], const Grocery::string &s)
{
	return strcmp(s.str, c_str) == 0;
}

bool Grocery::operator==(const Grocery::string &s1, const Grocery::string &s2)
{
	return strcmp(s1.str, s2.str) == 0;
}

bool Grocery::operator!=(const Grocery::string &s, const char c_str[])
{
	return !(s == c_str);
}

bool Grocery::operator!=(const char c_str[], const Grocery::string &s)
{
	return !(s == c_str);
}

bool Grocery::operator!=(const Grocery::string &s1, const Grocery::string &s2)
{
	return !(s1 == s2);
}

Grocery::string::iterator Grocery::string::begin() const
{
	return str;
}

Grocery::string::iterator Grocery::string::end() const
{
	return str + size;
}

Grocery::string::const_iterator Grocery::string::cbegin() const
{
	return str;
}

Grocery::string::const_iterator Grocery::string::cend() const
{
	return str + size;
}

std::istream &Grocery::operator>>(std::istream &is, Grocery::string &s)
{
	char next = is.get();
	s.size = 0;
	while (next != ' ' && next != '\n' && next != '\t' && next != '\0' && !is.fail())
	{
		if (s.size == s.capacity)
		{
			char *newstr = new char[s.size * 2];
			s.capacity *= 2;
			strncpy(newstr, s.str, s.size);
			delete[] s.str;
			s.str = newstr;
		}
		s.str[s.size] = next;
		s.size++;
		next = is.get();
	}
	s.str[s.size] = '\0';
	return is;
}

std::ostream &Grocery::operator<<(std::ostream &os, const Grocery::string &s)
{
	os << s.str;
	return os;
}
