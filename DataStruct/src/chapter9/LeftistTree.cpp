#include "chapter9/LeftistTree.h"
#include <algorithm>

using namespace std;

namespace Chapter9
{
	template <class T>
	bool MinLeftistTree<T>::IsEmpty() const
	{
		return root == nullptr;
	}

	template<class T>
	const T& MinLeftistTree<T>::Top() const
	{
		if (IsEmpty())
			throw "Tree is empty";
		return root->data;
	}

	template<class T>
	void MinLeftistTree<T>::Pop()
	{
		if (IsEmpty())
			throw "Tree is empty";
		DeleteMin();
	}

	template<class T>
	void MinLeftistTree<T>::Push(const T& p)
	{
		Insert(p);
	}

	template<class T>
	const T& MinLeftistTree<T>::GetMin() const
	{
		if (IsEmpty())
			throw "Tree is empty";
		return root->data;
	}

	template<class T>
	void MinLeftistTree<T>::Insert(const T& data)
	{
		LeftistNode<T>* newNode = new LeftistNode<T>(data);
		root = Meld(root, newNode);
	}

	template<class T>
	T& MinLeftistTree<T>::DeleteMin()
	{
		if (IsEmpty())
			throw "Tree is empty";

		T& minData = root->data;
		LeftistNode<T>* oldRoot = root;
		root = Meld(root->LeftChild, root->RightChild);
		delete oldRoot;
		return minData;
	}

	template<class T>
	void MinLeftistTree<T>::Meld(MinLeftistTree<T> *b)
	{
		if (!root)
			root = b->root;
		else if (b->root)
			root = Meld(root, b->root);
		b->root = 0;
	}

	template<class T>
	LeftistNode<T>* MinLeftistTree<T>::Meld(LeftistNode<T>* a, LeftistNode<T>* b)
	{
		if (a->data > b->data)
			swap(a, b);

		if (!a->RightChild)
			a->RightChild = b;
		else
			a->RightChild = Meld(a->RightChild, b);

		if (!a->LeftChild || a->LeftChild->shortest < a->RightChild->shortest)
			swap(a->LeftChild, a->RightChild);

		if (!a->RightChild)
			a->shortest = 1;
		else a->shortest = a->RightChild->shortest + 1;
		
		return a;
	}

	void TestLeftistTree()
	{
		LeftistNode<int>* n1 = new LeftistNode<int>(20);
		MinLeftistTree<int>* t1 = new MinLeftistTree<int>(n1);
		t1->Push(10);
		t1->Push(5);
		t1->Push(18);
		t1->Push(6);

		LeftistNode<int>* n2 = new LeftistNode<int>(12);
		MinLeftistTree<int>* t2 = new MinLeftistTree<int>(n2);
		t2->Push(14);
		t2->Push(4);
		t2->Push(22);

		cout << *t1 << endl;
		cout << *t2 << endl;

		t1->Meld(t2);
		cout << *t1 << endl;
	}
}