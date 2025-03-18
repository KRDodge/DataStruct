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
		ChainNode(const T& element, ChainNode<T>* next = nullptr)
			: data(element), link(next) {}
		~ChainNode()
		{
			delete link;
		}
		
		ChainNode<T>* link;
		T data;
	private:
	};
}
