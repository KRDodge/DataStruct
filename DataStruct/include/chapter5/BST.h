#pragma once
#include "chapter5/Dictionary.h"
#include "chapter5/Tree.h"

namespace Chapter5
{
	template <class K, class E>
	class BST : Dictionary<K,E>
	{
	public:
		bool IsEmpty() const override;
		pair<K, E> Get(const K&) const override;
		void Insert(const pair<K, E>&) override;
		void Delete(const K&) override;

		pair<K, E>* Get(TreeNode<pair<K, E>>* p, const K& k);
		void Split(const K& k, BST<K, E>& small, pair<K, E>*& mid, BST<K, E>& big);

	private:
		TreeNode<pair<K,E>>* root;
	};
}