#pragma once
#include "chapter3/ChangeSize.h"
#include <iostream>
#include <algorithm>

namespace Chapter3
{
	enum Operation
	{
		Push,
		Pop,
	};

	template <class T>
	class Queue
	{
	public:
		Queue(int capacity = 10) : capacity(capacity)
		{
			if (capacity < 1)
				throw "Capacity cannot be less than 1";

			lastOp = Operation::Pop;
			queue = new T[capacity];
			front = rear = 0;
		}

		~Queue()
		{
			delete[] queue;
		}

		bool IsEmpty() const 
		{
			return front == rear;
		}

		T& Front() const
		{
			if (IsEmpty())
				throw "queue is empty";

			return queue[(front + 1) % capacity];
		}

		T& Rear() const
		{
			if (IsEmpty())
				throw "queue is empty";

			return queue[rear];
		}

		void Push(const T& x)
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

		void Pop()
		{
			if (IsEmpty())
				throw "queue is empty";

			lastOp = Operation::Pop;
			front = (front + 1) % capacity;
			queue[front].~T();
		}

		int Capacity() const;
		int Size() const;

		void Split(Queue<T>& q1, Queue<T>& q2);

		void Merge(const Queue<T>& q1, const Queue<T>& q2);

	private:
		T* queue;
		int front;
		int rear;
		int capacity;
		Operation lastOp;
	};

	void ModifyQueue();
}
