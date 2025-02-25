#include "include/chapter3/Queue.h"
#include "include/chapter3/ChangeSize.h"
#include <iostream>

using namespace std;

namespace Chapter3
{
	template <class T>
	Queue<T>::Queue()
	{

	}

	template <class T>
	Queue<T>::Queue(int capacity) : capacity(capacity)
	{
		if (capacity < 1)
			throw "Capacity cannot be less than 1";

		queue = new T[capacity];
		front = rear = 0;
	}

	template <class T>
	Queue<T>::~Queue()
	{
		delete[] queue;
	}
	
	template<class T>
	bool Queue<T>::IsEmpty() const
	{
		return front == rear;
	}

	template<class T>
	T& Queue<T>::Front() const
	{
		if (IsEmpty())
			throw "queue is empty";

		return queue[(front + 1) % capacity];
	}

	template<class T>
	T& Queue<T>::Rear() const
	{
		if (IsEmpty())
			throw "queue is empty";

		return queue[rear];
	}

	template<class T>
	void Queue<T>::Push(const T& x)
	{
		if ((rear + 1) % capacity == front)
		{
			ChangeSize1D(queue, capacity, 2 * capacity);
			capacity *= 2;
		}

		rear = (rear + 1) % capacity;
		queue[rear] = x;
	}

	template<class T>
	void Queue<T>::Pop()
	{
		if (IsEmpty())
			throw "queue is empty";

		front = (front + 1) % capacity;
	}
}
