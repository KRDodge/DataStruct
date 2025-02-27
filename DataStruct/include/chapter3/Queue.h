#pragma once

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
		Queue();
		Queue(int capacity = 10);
		~Queue();

		bool IsEmpty() const;
		T& Front() const;
		T& Rear() const;

		void Push(const T& x);
		void Pop();

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
