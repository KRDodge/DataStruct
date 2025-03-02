#include "Chain.h"
#include "include/chapter4/Chain.h"


namespace Chapter4
{
	Chain::Chain()
	{
		first = new ChainNode()
	}
	Chain::~Chain()
	{
	}

	Chain::Insert(ChainNode* x)
	{
		if (first)
		{
			x->link;
		}
	}

	int Chain::Count()
	{
		int count = 0;
		ChainNode temp = first;
		while (temp->link != null)
		{
			temp = temp->link;
			count++;
		}
		return count;
	}

	Chain::Delete(ChainNode* x, ChainNode* y)
	{
		if (x == first)
			first = first->link;
		else
			y->link = x->link;
		delete x;
	}
}


