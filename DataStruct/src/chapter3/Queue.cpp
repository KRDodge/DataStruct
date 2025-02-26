#include "chapter3/Queue.h"
#include "chapter3/ChangeSize.h"
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

		lastOp = Operation::Pop;
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
			T* newQueue = new T[2 * capacity];
			int start = (front + 1) % capacity;
			if (start < 2)
				copy(queue + start, queue + start + capacity - 1, newQueue);
			else
			{
				copy(queue + start, queue + capacity, newQueue);
				copy(queue, queue + rear + 1, newQueue + capacity - start);
			}
			front = 2 * capacity - 1;
			rear = capacity - 2;
			capacity *= 2;
			delete[] queue;
			queue = newQueue;
		}

		lastOp = Operation::Push;
		rear = (rear + 1) % capacity;
		queue[rear] = x;
	}

	template<class T>
	void Queue<T>::Pop()
	{
		if (IsEmpty())
			throw "queue is empty";

		lastOp = Operation.Pop;
		front = (front + 1) % capacity;
		queue[front].~T();
	}

	template<class T>
	int Queue<T>::Capacity() const
	{
		return capacity;
	}

	template<class T>
	int Queue<T>::Size() const
	{
		return (rear - front + capacity) % capacity;
	}

	template <class T>
	void Queue<T>::Split(Queue<T>& q1, Queue<T>& q2)
	{
		if (IsEmpty()) return;

		int half = Size() / 2;
		int size = Size() - half;

		for (int i = 0; i < size; i++)
		{
			q1.Push(queue[(front + 1 + i) % capacity]);
		}

		for (int i = size1; i < Size(); i++)
		{
			q2.Push(queue[(front + 1 + i) % capacity]);
		}
	}

	template <class T>
	void Queue<T>::Merge(const Queue<T>& q1, const Queue<T>& q2)
	{
		int newCapacity = q1.Size() + q2.Size() + 1;
		delete[] queue;
		queue = new T[newCapacity];
		capacity = newCapacity;
		front = 0;
		rear = 0;

		int size1 = q1.Size();
		int size2 = q2.Size();
		int index1 = (q1.front + 1) % q1.capacity;
		int index2 = (q2.front + 1) % q2.capacity;

		while (size1 > 0 && size2 > 0)
		{
			Push(q1.queue[index1]);
			index1 = (index1 + 1) % q1.capacity;
			size1--;

			Push(q2.queue[index2]);
			index2 = (index2 + 1) % q2.capacity;
			size2--;
		}

		while (size1 > 0)
		{
			Push(q1.queue[index1]);
			index1 = (index1 + 1) % q1.capacity;
			size1--;
		}

		while (size2 > 0)
		{
			Push(q2.queue[index2]);
			index2 = (index2 + 1) % q2.capacity;
			size2--;
		}
	}

	void ModifyQueue()
	{
		Queue<int> queue(3);

		queue.Push(1);
		queue.Push(2);
		queue.Push(3);
		queue.Pop();

		cout << queue.Front() << queue.Rear() << endl;
		cout << queue.Size() << queue.Capacity() << endl;
	}
}
