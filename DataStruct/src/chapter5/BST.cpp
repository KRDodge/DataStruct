#include "chapter5/BST.h"

namespace Chapter5
{
	template <class K, class E>
	bool BST<K, E>::IsEmpty() const
	{
		return root == nullptr;
	}

	template<class K, class E>
	pair<K, E>* BST<K, E>::Get(const K& k) const
	{
		Get(root, k);
	}

	template <class K, class E>
	void BST<K, E>::Insert(const pair<K, E>& e)
	{
		TreeNode<pair<K, E>>* p = root;
		TreeNode<pair<K, E>>* pp = nullptr;
		while (p)
		{
			pp = p;
			if (e.first < p->data.first)
				p = p->leftChild;
			else if (e.first > p->data.first)
				p = p->rightChild;
			else
			{
				p->data.second = e.second;
				return;
			}
		}

		p = new TreeNode<pair<K, E>>(e);
		if (root)
		{

			if (e.first < pp->data.first)
				pp->leftChild = p;
			else
				pp->rightChild = p;
		}
		else
			root = p;
	}

	template<class K, class E>
	void BST<K, E>::Delete(const K& e)
	{
		TreeNode<pair<K, E>>* p = root;
		TreeNode<pair<K, E>>* pp = nullptr;

		while (p && p->data.first != e)
		{
			pp = p;
			if (e < p->data.first)
				p = p->leftChild;
			else
				p = p->rightChild;
		}

		if (!p)
			return;

		TreeNode<pair<K, E>>* child = nullptr;
		if (p->leftChild)
			child = p->leftChild;
		else if(p->rightChild)
			child = p->rightChild;

		if (!p->leftChild || !p->rightChild)
		{
			if (!pp)
				root = child;
			else if (pp->leftChild == p)
				pp->leftChild = child;
			else
				pp->rightChild = child;
			delete p;
		}


		TreeNode<pair<K, E>>* sp = p;
		TreeNode<pair<K, E>>* s = p->rightChild;

		while (s->leftChild)
		{
			sp = s;
			s = s->leftChild;
		}

		p->data = s->data;

		if (sp->leftChild == s)
			sp->leftChild = s->rightChild;
		else
			sp->rightChild = s->rightChild;

		delete s;
	}

	template<class K, class E>
	pair<K, E>* BST<K, E>::Get(TreeNode<pair<K, E>>** p, const K& k)
	{
		TreeNode<pair<K, E>>* currentNode = root;
		while (currentNode)
		{
			if (k < currentNode->data.first)
				currentNode = currentNode->leftChild;
			else if (k > currentNode->data.first)
				currentNode = currentNode->rightChild;
			else return &p->data;
		}
		return nullptr;
	}

	template<class K, class E>
	void BST<K, E>::Split(const K& k, BST<K, E>& small, pair<K, E>*& mid, BST<K, E>& big)
	{
		if (!root)
		{
			small.root = big.root = nullptr;
			return;
		}

		TreeNode<pair<K, E>>* sHead = new TreeNode<pair<K, E>>;
		TreeNode<pair<K, E>>* s = sHead;
		TreeNode<pair<K, E>>* bHead = new TreeNode<pair<K, E>>;
		TreeNode<pair<K, E>>* b = bHead;
		TreeNode<pair<K, E>>* currentNode = root;

		while (currentNode)
		{
			if (k < currentNode->data.first)
			{
				b->leftChild = currentNode;
				b = currentNode;
				currentNode = currentNode->leftChild;
			}
			else if (k > currentNode->data.first)
			{
				s->rightChild = currentNode;
				s = currentNode;
				currentNode = currentNode->rightChild;
			}
			else
			{
				s->rightChild = currentNode->leftChild;
				b->leftChild = currentNode->rightChild;
				small.root = sHead->rightChild;
				delete sHead;
				big.root = bHead->leftChild;
				delete bHead;
				mid = new pair<K, E>(currentNode->data.first, currentNode->data.second);
				delete currentNode;
				return;
			}
			s->rightChild = b->leftChild = 0;
			small.root = sHead->rightChild;
			delete sHead;
			big.root = bHead->leftChild;
			delete bHead;
			mid = nullptr;
			return;
		}
	}
}