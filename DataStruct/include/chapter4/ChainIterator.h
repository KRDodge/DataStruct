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

        T& operator*() const { return current->data; }
        T* operator->() const { return &(current->data); } // 🔥 올바른 포인터 반환

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

    private:
        ChainNode<T>* current;
	};
}