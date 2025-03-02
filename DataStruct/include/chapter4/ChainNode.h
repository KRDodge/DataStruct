#pragma once

namespace Chapter4
{
	class ChainNode {
		friend class Chain;
	public:
		ChainNode(int element = 0, ChainNode* next = 0)
		{
			data = element;
			link = next;
		}

	private:
		int data;
		ChainNode* link;
	};
}
