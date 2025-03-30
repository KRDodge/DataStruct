#include "chapter9/BinomialHeap.h"

namespace Chapter9
{
	template <class T>
	bool BinomialHeap<T>::IsEmpty() const
	{
		return min == nullptr;
	}

	template<class T>
	const T& BinomialHeap<T>::Top() const
	{
		if (IsEmpty())
			throw "Tree is empty";
		return min->data;
	}

	template<class T>
	void BinomialHeap<T>::Pop()
	{
		if (IsEmpty())
			throw "Tree is empty";

		DeleteMin();
	}

	template<class T>
	void BinomialHeap<T>::Push(const T& p)
	{
		Insert(p);
	}

	template<class T>
	const T& BinomialHeap<T>::Min() const
	{
		if (IsEmpty())
			throw "Tree is empty";
		return min->data;
	}

	template<class T>
	void BinomialHeap<T>::Insert(const T& d)
	{
		BinomialNode<T>* node = new BinomialNode<T>{ d, nullptr, nullptr, 0 };
		BinomialHeap<T> temp(node);
		Meld(&temp);
	}

	template<class T>
	T& BinomialHeap<T>::DeleteMin()
	{
		if (IsEmpty()) throw "Heap is empty";

		// Step 1: min 찾아서 제거
		BinomialNode<T>* prevMin = nullptr;
		BinomialNode<T>* curr = min;
		BinomialNode<T>* prev = nullptr;
		BinomialNode<T>* scan = min;

		BinomialNode<T>* minNode = scan;
		T& minData = minNode->data;

		BinomialNode<T>* child = minNode->child;
		BinomialNode<T>* reversed = nullptr;
		while (child) 
		{
			BinomialNode<T>* next = child->link;
			child->link = reversed;
			reversed = child;
			child = next;
		}

		delete minNode;
		min = nullptr;
		BinomialHeap<T> childHeap(reversed);
		Meld(&childHeap);

		return minData;
	}

	template<class T>
	void BinomialHeap<T>::Meld(BinomialHeap<T>* b)
	{
		if (min == nullptr) 
		{
			min = b->GetMin();
			b->Initialize();
			return;
		}

		BinomialNode<T>* h1 = min;
		BinomialNode<T>* h2 = b->min;
		BinomialNode<T>* newHead = nullptr;
		BinomialNode<T>** pos = &newHead;

		while (h1 && h2) 
		{
			if (h1->degree <= h2->degree) {
				*pos = h1;
				h1 = h1->link;
			}
			else {
				*pos = h2;
				h2 = h2->link;
			}
			pos = &((*pos)->link);
		}
		if (h1)
			*pos = h1;
		else
			*pos = h2;

		min = newHead;
		b->Initialize();
	}
}
