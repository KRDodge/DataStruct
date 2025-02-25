#pragma once

namespace Chapter3
{
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

	private:
		T* queue;
		int front;
		int rear;
		int capacity;
	};
}
