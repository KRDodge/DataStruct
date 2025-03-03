#pragma once
#include "chapter4/ChainNode.h"
#include <iostream>

using namespace std;

namespace Chapter4
{
	template <class T>
	class Chain {
	public:
		Chain();
		~Chain();

		void Insert(ChainNode<T>* x);
		int Length();
		void Delete(ChainNode<T>* x);
		void Delete(ChainNode<T>* x, ChainNode<T>* y);
		
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
	};

	void ModifyChain();
}