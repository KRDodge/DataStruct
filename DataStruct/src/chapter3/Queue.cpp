#include "chapter3/Queue.h"

using namespace std;

namespace Chapter3
{

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

		for (int i = 0; i < half; i++)
		{
			q1.Push(queue[(front + 1 + i) % capacity]);
		}

		for (int i = size; i < Size(); i++)
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
