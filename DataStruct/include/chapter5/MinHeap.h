#pragma once
#include "chapter5/MaxPQ.h"
#include "chapter3/Queue.h"

using namespace Chapter3;

namespace Chapter5
{
	template <class T>
	class MinHeap : MaxPQ<T>
	{
	public:
		MinHeap(int capacity = 10);
		~MinHeap();

		bool IsEmpty() const override;
		const T& Top() const override;
		void Pop() override;
		void Push(const T& p) override;

		void LevelOrder();

	private:
		T* heap;
		int heapSize;
		int capacity;
	};
	void MinHeapTest();
}