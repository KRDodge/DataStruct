#include "chapter3/Dequeue.h"
#include "chapter3/ChangeSize.h"
#include <iostream>

using namespace std;

namespace Chapter3
{
	template <class T>
	Dequeue<T>::Dequeue()
	{

	}

	template <class T>
	Dequeue<T>::Dequeue(int capacity) : capacity(capacity)
	{
		if (capacity < 1)
			throw "Capacity cannot be less than 1";

		dequeue = new T[capacity];
		rear = front = 0;
	}

	template <class T>
	Dequeue<T>::~Dequeue()
	{

	}

	template <class T>
	bool Dequeue<T>::IsEmpty() const
	{
		return front == rear;
	}

	template<class T>
	T& Dequeue<T>::Front() const
	{
		return dequeue[(front + 1) % capacity];
	}

	template<class T>
	T& Dequeue<T>::Rear() const
	{
		return dequeue[rear];
	}

	template <class T>
	void Dequeue<T>::PushFront(const T& x)
	{
		if ((rear + 1) % capacity == front)
		{
			T* newQueue = new T[2 * capacity];
			int start = (front + 1) % capacity;
			if (start < 2)
				copy(dequeue + start, dequeue + start + capacity - 1, newQueue);
			else
			{
				copy(dequeue + start, dequeue + capacity, newQueue);
				copy(dequeue, dequeue + rear + 1, newQueue + capacity - start);
			}
			front = 2 * capacity - 1;
			rear = capacity - 1;
			capacity *= 2;
			delete[] dequeue;
			dequeue = newQueue;
		}

		front = (front - 1 + capacity) % capacity;
		dequeue[front] = x;
	}

	template <class T>
	void Dequeue<T>::PushRear(const T& x)
	{
		if ((rear + 1) % capacity == front)
		{
			T* newQueue = new T[2 * capacity];
			int start = (front + 1) % capacity;
			if (start < 2)
				copy(dequeue + start, dequeue + start + capacity - 1, newQueue);
			else
			{
				copy(dequeue + start, dequeue + capacity, newQueue);
				copy(dequeue, dequeue + rear + 1, newQueue + capacity - start);
			}
			front = 2 * capacity - 1;
			rear = capacity - 1;
			capacity *= 2;
			delete[] dequeue;
			dequeue = newQueue;
		}
		dequeue[rear] = x;
		rear = (rear + 1) % capacity;
	}

	template <class T>
	void Dequeue<T>::PopFront()
	{
		if (IsEmpty())
			throw "Dequeue is Empty";

		front = (front + 1) % capacity;
		dequeue[front].~T();
	}

	template <class T>
	void Dequeue<T>::PopRear()
	{
		if (IsEmpty())
			throw "Dequeue is Empty";
		rear = (rear - 1 + capacity) % capacity;
		dequeue[rear].~T();
	}

	template<class T>
	int Dequeue<T>::Capacity() const
	{
		return capacity;
	}

	template<class T>
	int Dequeue<T>::Size() const
	{
		return (rear - front + capacity) % capacity;
	}

	void ModifyDequeue()
	{
		Dequeue<int> queue(3);

		queue.PushRear(1);
		queue.PushRear(2);
		queue.PushFront(3);
		cout << queue.Front() << queue.Rear() << endl;

		queue.PopFront();
		cout << queue.Size() << queue.Capacity() << endl;

	}
}
