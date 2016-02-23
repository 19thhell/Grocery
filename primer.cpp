#include "primer.h"
#include <stdexcept>

Grocery::StrBlob::StrBlob()
	: data(std::make_shared<std::vector<std::string>>())
{}

Grocery::StrBlob::StrBlob(std::initializer_list<std::string> il)
	: data(std::make_shared<std::vector<std::string>>(il))
{}

void Grocery::StrBlob::pop_back() {
	check(0, "pop back on empty StrBlob");
	data->pop_back();
}

std::string& Grocery::StrBlob::front() {
	check(0, "access front on empty StrBlob");
	data->front();
}

std::string& Grocery::StrBlob::back() {
	check(0, "access back on empty StrBlob");
	data->back();
}

void Grocery::StrBlob::check(size_type i, const std::string &msg) const {
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}
