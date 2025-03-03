#include "chapter4/Chain.h"
#include <iostream>

using namespace std;

namespace Chapter4
{
	template <class T>
	Chain<T>::Chain()
	{
		first = nullptr;
	}

	template <class T>
	Chain<T>::~Chain()
	{
	}

	template <class T>
	void Chain<T>::Insert(ChainNode<T>* x)
	{
		x->link = first;
		first = x;
	}

	template <class T>
	int Chain<T>::Length()
	{
		if (first == nullptr)
			return 0;
		int count = 1;
		ChainNode<T>* temp = first;
		while (temp->link != nullptr)
		{
			temp = temp->link;
			count++;
		}
		return count;
	}

	template <class T>
	void Chain<T>::Delete(ChainNode<T>* x)
	{
		if (first == nullptr || x == nullptr)
			return;

		if (first == x)
		{
			first = first->link;
			x = nullptr;
			delete x;
			return;
		}

		ChainNode<T>* temp = first;
		while (temp->link != nullptr && temp->link != x)
		{
			temp = temp->link;
		}

		if (temp->link == x)
		{
			temp->link = x->link;
			x = nullptr;
			delete x;
		}
	}

	template <class T>
	void Chain<T>::Delete(ChainNode<T>* x, ChainNode<T>* y)
	{
		if (x == first)
			first = first->link;
		else
			y->link = x->link;
		delete x;
	}

	void ModifyChain()
	{
		Chain<int> chain;

		ChainNode<int>* node1 = new ChainNode<int>(10);
		ChainNode<int>* node2 = new ChainNode<int>(20);
		ChainNode<int>* node3 = new ChainNode<int>(30);

		chain.Insert(node1);
		chain.Insert(node2);
		chain.Insert(node3);

		cout << chain << endl;

		chain.Delete(node2);

		cout << chain << endl;
		cout << chain.Length() << endl;
	}
}

