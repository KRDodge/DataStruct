#pragma once

namespace Chapter10
{
	template <class K, class E> class AVL;

	template<class K, class E>
	class AvlNode 
	{
	public:
		friend class AVL<K, E>;
		AvlNode(const K& k, const E& e)
		{
			key = k;
			element = e;
			bf = 0;
			leftChild = rightChild = 0;
		};
	private:
		K key;
		E element;
		int bf;
		AvlNode<K, E>* leftChild;
		AvlNode<K, E>* rightChild;
	};

	template <class K, class E>
	class AVL 
	{
	public:
		AVL() : root(nullptr) {};
		E& Search(const K&) const;
		void Insert(const K&, const E&);
		void Deelte(const K&);

	private:
		AvlNode<K, E>* root;
	};
}