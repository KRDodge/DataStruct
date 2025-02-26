#include "chapter3/Dequeue.h"

namespace Chapter3
{
	template <class T>
	Dequeue<T>::Dequeue()
	{

	}

	template <class T>
	Dequeue<T>::Dequeue(int capacity) : capacity(capacity)
	{
		dequeue = new T[capacity];
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
		return queue[(front + 1) % capacity];
	}

	template<class T>
	T& Dequeue<T>::Rear() const
	{
		return queue[(rear - 1 + capacity) % capacity];
	}

	template <class T>
	void Dequeue<T>::PushFront(const T& x)
	{
		
	}

	template <class T>
	void Dequeue<T>::PushRear(const T& x)
	{

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
	void ModifyDeDequeue()
	{
	}
}
