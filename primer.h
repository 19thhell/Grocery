#ifndef GROC_PRIMER_H
#define GROC_PRIMER_H
#include <memory>
#include <string>
#include <vector>

namespace Grocery {
	class StrBlob {
		public:
			typedef std::vector<std::string>::size_type size_type;
			StrBlob();
			StrBlob(std::initializer_list<std::string> il);
			size_type size() const { return data->size(); }
			bool empty() const { return data->empty(); }
			void push_back(const std::string &s) { data->push_back(s); }
			void pop_back();
			std::string& front();
			std::string& back();
		private:
			std::shared_ptr<std::vector<std::string>> data;
			void check(size_type i, const std::string &msg) const;
	};
}

#endif
