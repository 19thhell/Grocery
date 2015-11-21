#ifndef GROC_TREE_H
#define GROC_TREE_H

namespace Grocery {
	template <typename Key, typename Val>
	class red_black_tree {
		public:
			red_black_tree();
			~red_black_tree();
			void insert(const Key& key, const Val& val);
			bool contains(const Key& key);
			Val get(const Key& key);

		private:
	};
}

#include "tree.cpp"
#endif
