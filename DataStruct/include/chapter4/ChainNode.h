#pragma once
#include "chapter4/Chain.h"
#include <iostream>

using namespace std;

namespace Chapter4
{
	template <class T> class Chain;

	template <class T>
	class ChainNode {
		friend class Chain<T>;
	public:

		ChainNode(T element = 0, ChainNode<T>* next = 0)
		{
			data = element;
			link = next;
		}
		~ChainNode()
		{
			delete link;
		}
		
		ChainNode<T>* link;
		T data;
	private:
	};
}
