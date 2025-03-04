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
		if (!x)
			return;

		x->link = nullptr;

		if (first)
		{
			last->link = x;
			last = x;
		}
		else
		{
			first = x;
			last = x;
		}
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
		if (!first || !x)
			return;

		if (first == x)
		{
			first = first->link;
			if (!first)
				last = nullptr;
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
			if (last == x)
				last = temp;
			x = nullptr;
			delete x;
		}
	}

	template <class T>
	void Chain<T>::Delete(ChainNode<T>* x, ChainNode<T>* y)
	{
		if (!first || !x)
			return;


		if (x == first)
		{
			first = first->link;
			if (!first)
				last = nullptr;
		}
		else if (y && y->link == x)
		{
			y->link = x->link;
			if (x == last)
				last = y;
		}
		delete x;
	}

	template<class T>
	void Chain<T>::InsertBack(const T& e)
	{
		{
			if (first)
			{
				last->link = new ChainNode<T>(e);
				last = last->link;
			}
			else
				first = last = new ChainNode<T>(e);
		}
	}

	template<class T>
	void Chain<T>::Concatenate(Chain<T>& b)
	{
		if (first)
		{
			last->link = b.first;
			last = b.last;
		}
		else
		{
			first = b.first;
			last = b.last;
		}

		b.first = b.last = nullptr;
	}

	template<class T>
	void Chain<T>::Reverse()
	{
		ChainNode<T>* current = first;
		ChainNode<T>* previous = nullptr;

		last = first;

		while (current)
		{
			ChainNode<T>* r = previous;
			previous = current;
			current = current->link;
			previous->link = r;
		}
		first = previous;
	}

	template<class T>
	T& Chain<T>::Max()
	{
		if (!first)
			throw "first is nullptr";

		ChainNode<T>* current = first;
		T& maxVal = first->data;
		while (current->link)
		{
			current = current->link;
			maxVal = max(current->data, maxVal);
		}

		return maxVal;
	}

	template<class T>
	T& Chain<T>::Min()
	{
		if (!first)
			throw "first is nullptr";

		ChainNode<T>* current = first;
		T& minVal = first->data;
		while (current->link)
		{
			current = current->link;
			minVal = min(current->data, minVal);
		}

		return minVal;
	}

	template<class T>
	T* Chain<T>::ToArray()
	{
		int length = Length();
		if (length == 0)
			return nullptr;

		T* tArray = new T[length];

		ChainNode<T>* current = first;
		T* arrEnd = tArray;

		while (current)
		{
			*arrEnd = current->data;
			++arrEnd;
			current = current->link;
		}

		return tArray;
	}

	template<class T>
	T& Chain<T>::Front()
	{
		if (!first)
			throw "no first";

		return first->data;
	}

	template<class T>
	T& Chain<T>::Back()
	{
		if (!last)
			throw "no last";

		return last->data;
	}

	template<class T>
	T& Chain<T>::Get(int index)
	{
		if (index < 0 || index >= Length())
			throw "index out of range";

		ChainNode<T>* current = first;
		for (int i = 1; i <= index; ++i)
		{
			current = current->link;
		}
		return current->data;
	}

	template<class T>
	void Chain<T>::Insert(const T& e, int index)
	{
		if (index < 0 || index > Length())
			return;

		ChainNode<T>* newNode = new ChainNode<T>(e);
		if (index == 0)
		{
			newNode->link = first;
			first = newNode;
			return;
		}

		ChainNode<T>* current = first;
		for (int i = 1; i < index; ++i)
		{
			current = current->link;
		}

		newNode->link = current->link;
		current->link = newNode;
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

		chain.Reverse();
		cout << chain << endl;
		cout << chain.Min() << endl;

		chain.Insert(40, 2);
		cout << chain << endl;
		cout << chain.Get(2) << endl;
	}
}

