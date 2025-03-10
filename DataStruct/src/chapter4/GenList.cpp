#include "chapter4/GenList.h"
#include <algorithm>
#include "math.h"

using namespace std;

namespace Chapter4
{
	template<class T>
	GenList<T>::GenList()
	{
	}

	template<class T>
	GenList<T>::~GenList()
	{
		if (first)
		{
			Delete(first);
			first = nullptr;
		}
	}

	template<class T>
	void GenList<T>::Copy(const GenList<T>& l) const
	{

		first = Copy(l.first);
		GenListNode<T>* q = nullptr;

		if()
	}

	template<class T>
	GenListNode<T>* GenList<T>::Copy(GenListNode<T>* p)
	{
		GenListNode<T>* q = nullptr;
		if (p)
		{
			q = new GenListNode<T>;
			q->tag = p->tag;
			if (p->tag)
				q->down = Copy(p->down);
			else
				q->data = p->data;

			q->next = Copy(p->next);
		}
	}
	template<class T>
	void GenList<T>::Delete(GenListNode<T>* x)
	{
		x->ref--;
		if (!x->ref)
		{
			GenListNode<T>* y = x;
			while (y->next)
			{
				y = y->next;
				if (y->tag == 1)
					Delete(y->down);
				y->next = av;
				av = x;
			}
		}
	}

	template<class T>
	void GenList<T>::Insert(GenListNode<T>* x)
	{
		if (!first)
		{
			first = x;
			return;
		}

		GenListNode<T>* current = first;
		while (current->next)
			current = current->next;
		current->next = x;
	}

	template<class T>
	bool GenList<T>::operator==(const GenList<T>& l) const
	{
		return Equal(first, l.first);
	}

	template<class T>
	bool GenList<T>::Equal(GenListNode<T>* s, GenListNode<T>* t)
	{
		if (!s && !t)
			return true;

		if (s && t && (s->tag == t->tag))
		{
			if (s->tag)
				return Equal(s->down, t->down) && Equal(s->next, t->next);
			else
				return (s->data == t->data) && Equal(s->next, t->next);
		}
		return false;
	}

	template<class T>
	int GenList<T>::Depth()
	{
		return Depth(first);
	}

	template<class T>
	int GenList<T>::Depth(GenListNode<T>* s)
	{
		if (!s)
			return 0;

		GenListNode<T>* current = s;
		int m = 0;
		while (current)
		{
			if (current->tag)
				m = max(m, Depth(current->down));
			current = current->next;
		}
		return m + 1;
	}
}
