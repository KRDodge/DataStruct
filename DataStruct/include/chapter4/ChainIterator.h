#pragma once
#include "chapter4/Chain.h"

namespace Chapter4
{
    template <class T> class Chain;

    template <class T>
    class ChainIterator
    {
        friend class Chain<T>;

    public:
        ChainIterator(ChainNode<T>* startNode = nullptr) : current(startNode) {}

        T& operator*() const { return *current; }
        T* operator->() const { return &(current->data); }

        ChainIterator& operator++()
        {
            if (current) current = current->link;
            return *this;
        }

        ChainIterator operator++(int)
        {
            ChainIterator old = *this;
            if (current) current = current->link;
            return old;
        }

        bool operator!=(const ChainIterator& right) const
        {
            return current != right.current;
        }

        bool operator==(const ChainIterator& right) const
        {
            return current == right.current;
        }

        operator bool() const
        {
            return current != nullptr;
        }

        ChainNode<T>* GetNode() const { return current; }

    private:
        ChainNode<T>* current;
	};
}