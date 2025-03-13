#pragma once
#include "chapter5/MaxPQ.h"

namespace Chapter5
{
	template <class T>
	class MaxHeap : MaxPQ<T>
	{
	public:
		MaxHeap(int capacity = 10);
		~MaxHeap();

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

	void MaxHeapTest();
}