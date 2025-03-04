#pragma once
#include "chapter4/Chain.h"

namespace Chapter4
{
	template <class T> class Chain;

	class ChainIterator
	{
	public:
		ChainIterator(ChainNode<T>* startNode = 0)
		{
			current = startNode;
		}

		T& operator*() const { return current->data; }
		T* operator->() const { return &current->data; }

		ChainIterator& operator++()
		{
			current = current->link;
			return *this;
		}

		ChainIterator operator++(int)
		{
			ChainIterator old = *this;
			current = current->link;
			return old;
		}

		bool operator!=(const ChainIterator right) const
		{
			return current != right.current;
		}

		bool operator==(const ChainIterator right) const
		{
			return current == right.current;
		}

	private:
		ChainNode<T>* current;
	};
}

