#pragma once
namespace Chapter3
{
	template <class T>
	class Dequeue
	{
	public:
		Dequeue();
		Dequeue(int capacity = 10);
		~Dequeue();

		bool IsEmpty() const;
		T& Front() const;
		T& Rear() const;

		void PushFront(const T& x);
		void PushRear(const T& x);
		
		void PopFront();
		void PopRear();

		int Capacity() const;
		int Size() const;

	private:
		T* dequeue;
		int front;
		int rear;
		int capacity;
	};

	void ModifyDequeue();
}

