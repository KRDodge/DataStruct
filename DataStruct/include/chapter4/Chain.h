#pragma once
#include "include/chapter4/ChainNode.h"

namespace Chapter4
{

	class Chain {
	public:
		Chain();
		~Chain();

		void Insert(ChainNode* x);
		int Count();

	private:
		ChainNode* first;
	};
	
}