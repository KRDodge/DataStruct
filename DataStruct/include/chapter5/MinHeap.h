#pragma once
#include "chapter5/MaxPQ.h"

namespace Chapter5
{
	template <class T>
	class MinHeap : MaxPQ
	{
	public:
		MinHeap(int capacity = 10);
		~MinHeap();

		bool IsEmpty() const override;
		const T& Top() override;
		void Pop() override;
		void Push(const T& p) override;

	private:
		T* heap;
		int heapSize;
		int capacity;
	};
}