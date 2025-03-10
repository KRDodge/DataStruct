#include "chapter4/DblList.h"

namespace Chapter4
{

	void DblList::Delete(DblListNode* x)
	{
		if (x == first)
			throw "Deletion of header node not permitted";
		if (x == last)
			last = x->left;

		x->left->right = x->right;
		x->right->left = x->left;
		delete x;
	}

	void DblList::Insert(DblListNode* p, DblListNode* x)
	{
		p->left = x;
		p->right = x->right;

		x->right->left = p;
		x->right = p;

		if (x == last)
			last = p;
	}

	void DblList::InsertFront(DblListNode* p)
	{
		first->left = p;
		p->right = first;
		p->left = nullptr;
		first = p;

		if (!last)
			last = p;
	}

	void DblList::InsertBack(DblListNode* p)
	{
		last->right = p;
		p->left = last;
		p->right = nullptr;
		last = p;

		if (!first)
			first = p;
	}

	void DblList::Concatenate(DblList* p)
	{
		if (!first)
		{
			first = p->first;
			last = p->last;
		}
		else
		{
			last->right = p->first;
			p->first->left = last;
			last = p->last;
		}

		p->first = p->last = nullptr;
	}

}
