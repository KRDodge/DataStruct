#pragma once
#include "chapter4/ChainNode.h"
#include "chapter4/ChainIterator.h"
#include <iostream>

using namespace std;

namespace Chapter4
{
	template <class T>
	class Chain {
	public:
		using ChainIterator = ChainIterator<T>;

		Chain()
		{
			first = nullptr;
		}
		~Chain() 
		{
			delete first; 
			delete last;

			first = nullptr;
			last = nullptr;
		}

		void Insert(ChainNode<T>* x)
		{
			if (!x)
				return;

			x->link = nullptr;

			if (first)
			{
				last->link = x;
				last = x;
			}
			else
			{
				first = x;
				last = x;
			}
		}

		int Length()
		{
			if (first == nullptr)
				return 0;
			int count = 1;
			ChainNode<T>* temp = first;
			while (temp->link != nullptr)
			{
				temp = temp->link;
				count++;
			}
			return count;
		}

		void Delete(ChainNode<T>* x)
		{
			if (!first || !x)
				return;

			if (first == x)
			{
				first = first->link;
				if (!first)
					last = nullptr;
				x = nullptr;
				delete x;
				return;
			}

			ChainNode<T>* temp = first;
			while (temp->link != nullptr && temp->link != x)
			{
				temp = temp->link;
			}

			if (temp->link == x)
			{
				temp->link = x->link;
				if (last == x)
					last = temp;
				x = nullptr;
				delete x;
			}
		}

		void Delete(ChainNode<T>* x, ChainNode<T>* y)
		{
			if (!first || !x)
				return;


			if (x == first)
			{
				first = first->link;
				if (!first)
					last = nullptr;
			}
			else if (y && y->link == x)
			{
				y->link = x->link;
				if (x == last)
					last = y;
			}
			delete x;
		}

		void InsertBack(const T& e)
		{
			{
				if (first)
				{
					last->link = new ChainNode<T>(e);
					last = last->link;
				}
				else
					first = last = new ChainNode<T>(e);
			}
		}
		void Concatenate(Chain<T>& b)
		{
			if (first)
			{
				last->link = b.first;
				last = b.last;
			}
			else
			{
				first = b.first;
				last = b.last;
			}

			b.first = b.last = nullptr;
		}

		void Reverse()
		{
			ChainNode<T>* current = first;
			ChainNode<T>* previous = nullptr;

			last = first;

			while (current)
			{
				ChainNode<T>* r = previous;
				previous = current;
				current = current->link;
				previous->link = r;
			}
			first = previous;
		}

		T& Max()
		{
			if (!first)
				throw "first is nullptr";

			ChainNode<T>* current = first;
			T& maxVal = first->data;
			while (current->link)
			{
				current = current->link;
				maxVal = max(current->data, maxVal);
			}

			return maxVal;
		}

		T& Min()
		{
			if (!first)
				throw "first is nullptr";

			ChainNode<T>* current = first;
			T& minVal = first->data;
			while (current->link)
			{
				current = current->link;
				minVal = min(current->data, minVal);
			}

			return minVal;
		}

		T* ToArray()
		{
			int length = Length();
			if (length == 0)
				return nullptr;

			T* tArray = new T[length];

			ChainNode<T>* current = first;
			T* arrEnd = tArray;

			while (current)
			{
				*arrEnd = current->data;
				++arrEnd;
				current = current->link;
			}

			return tArray;
		}

		T& Front()
		{
			if (!first)
				throw "no first";

			return first->data;
		}
		T& Back()
		{
			if (!last)
				throw "no last";

			return last->data;
		}

		T& Get(int index)
		{
			if (index < 0 || index >= Length())
				throw "index out of range";

			ChainNode<T>* current = first;
			for (int i = 1; i <= index; ++i)
			{
				current = current->link;
			}
			return current->data;
		}

		void Insert(const T& e, int index)
		{
			if (index < 0 || index > Length())
				return;

			ChainNode<T>* newNode = new ChainNode<T>(e);
			if (index == 0)
			{
				newNode->link = first;
				first = newNode;
				return;
			}

			ChainNode<T>* current = first;
			for (int i = 1; i < index; ++i)
			{
				current = current->link;
			}

			newNode->link = current->link;
			current->link = newNode;
		}

		ChainIterator begin() { return ChainIterator(first); }
		ChainIterator end() { return ChainIterator(nullptr); }
		
		template <class T>
		friend ostream& operator<<(std::ostream& os, const Chain<T>& chain)
		{
			ChainNode<T>* current = chain.first;
			while (current != nullptr)
			{
				os << current->data;
				if (current->link != nullptr)
					os << " -> ";				
				current = current->link;
			}
			return os;
		}

	private:
		ChainNode<T>* first;
		ChainNode<T>* last;
	};

	void ModifyChain();
}