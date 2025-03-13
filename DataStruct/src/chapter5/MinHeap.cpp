#include "chapter5/MinHeap.h"
#include "chapter3/ChangeSize.h"
#include <iostream>

using namespace std;

namespace Chapter5
{
	template <class T>
	MinHeap<T>::MinHeap(int _capacity)
	{
		if (_capacity < 1)
			throw "capacity must be more than 0";

		capacity = _capacity;
		heapSize = 0;
		heap = new T[capacity + 1];
	}

	template<class T>
	MinHeap<T>::~MinHeap()
	{
		delete[] heap;
	}

	template <class T>
	bool MinHeap<T>::IsEmpty() const
	{
		return heapSize == 0;
	}

	template<class T>
	const T& MinHeap<T>::Top() const
	{
		if (IsEmpty())
			throw "capacity must be more than 0";
		return heap[1];
	}

	template <class T>
	void MinHeap<T>::Push(const T& e)
	{
		if (heapSize == capacity)
		{
			ChangeSize1D(heap, capacity, capacity * 2);
			capacity *= 2;
		}
		int currentNode = ++heapSize;
		while (currentNode != 1 && heap[currentNode / 2] > e)
		{
			heap[currentNode] = heap[currentNode / 2];
			currentNode /= 2;
		}
		heap[currentNode] = e;
	}

	template<class T>
	void MinHeap<T>::LevelOrder()
	{
		if (IsEmpty())
			return;

		for (int i = 1; i <= heapSize; i++)
		{
			cout << heap[i] << " ";
		}
	}

	template <class T>
	void MinHeap<T>::Pop()
	{
		if (IsEmpty())
			throw "Heap is Empty";

		heap[1].~T();
		T lastE = heap[heapSize--];
		int currentNode = 1;
		int child = 2;
		while (child <= heapSize)
		{
			if (child < heapSize && heap[child] > heap[child + 1])
				child++;

			if (lastE <= heap[child])
				break;

			heap[currentNode] = heap[child];
			currentNode = child;
			child *= 2;
		}
		heap[currentNode] = lastE;
	}

	void MinHeapTest()
	{
		MinHeap<int> h;
		h.Push(5);
		h.Push(4);
		h.Push(3);
		h.Push(2);
		h.Push(1);

		h.LevelOrder();
		cout << endl;
	}
}