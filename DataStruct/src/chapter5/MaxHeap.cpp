#include "chapter5/MaxHeap.h"
#include "chapter3/ChangeSize.h"

namespace Chapter5
{
	template <class T>
	MaxHeap<T>::MaxHeap(int _capacity = 10)
	{
		if (capacity < 1)
			throw "capacity must be more than 0";

		capacity = _capacity;
		heapSize = 0;
		heap = new T[capacity + 1];
	}

	template <class T>
	bool MaxHeap<T>::IsEmpty() const
	{
		return heapSize == 0;
	}

	template <class T>
	void MaxHeap<T>::Push(const T& e)
	{
		if (heapSize == capacity)
		{
			ChangeSize1D(heap, capacity, capacity * 2);
			capacity *= 2;
		}
		int currentNode = ++heapSize;
		while (currentNode != 1 && heap[currentNode / 2] < e)
		{
			heap[currentNode] = heap[currentNode / 2];
			currentNode /= 2;
		}
		heap[currentNode] = e;
	}

	template <class T>
	void MaxHeap<T>::Pop()
	{
		if (IsEmpty())
			throw "Heap is Empty";

		heap[1].~T();
		T lastE = heap[heapSize--];
		int currentNode = 1;
		int child = 2;
		while (child <= heapSize)
		{
			if (child < heapSize && heap[child] < heap[child + 1])
				child++;

			if (lastE >= heap[child])
				break;

			heap[currentNode] = heap[child];
			currentNode = child;
			child *= 2;
		}
		heap[currentNode] = lastE;
	}
}