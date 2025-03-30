#include "chapter10/AVL.h"

namespace Chapter10
{
	template <class K, class E>
	void AVL<K,E>::Insert(const K& k, const E& e)
	{
		if (root == nullptr)
		{
			root = new AvlNode<K, E>(k, e);
			return;
		}

		AvlNode<K, E>* a = nullptr;
		AvlNode<K, E>* pa = nullptr;
		AvlNode<K, E>* p = root;
		AvlNode<K, E>* pp = nullptr;

		while (p)
		{
			if (p->bf)
			{
				a = p;
				pa = pp;
			}
			if (k < p->key)
			{
				pp = p;
				p = p->leftChild;
			}
			else if (k > p->key)
			{
				pp = p;
				p = p->rightChild;
			}
			else
			{
				p->element = e;
				return;
			}
		}

		AvlNode<K, E>* y = new AvlNode<K,E>(k, e);
		if (k < pp->key)
			pp->leftChild = y;
		else
			pp->rightChild = y;

		int d;
		AvlNode<K, E>* b;
		AvlNode<K, E>* c;

		if (k > a->key)
		{
			b = p = a->rightChild;
			d = -1;
		}
		else
		{
			b = p = a->leftChild;
			d = 1;
		}
		while (p != y)
		{
			if (k > p->key)
			{
				p->bf = -1;
				p = p->rightChild;
			}
			else
			{
				p->bf = 1;
				p = p->leftChild;
			}
		}

		if (!(a->bf) || !(a->bf + d))
		{
			a->bf += d;
			return;
		}

		if (d == 1)
		{
			if (b->bf == 1) //LL회전
			{
				a->leftChild = b->rightChild;
				b->rightChild = a;
				a->bf = 0;
				b->bf = 0;
			}
			else //LR회전
			{
				c = b->rightChild;
				b->rightChild = c->leftChild;
				a->leftChild = c->rightChild;
				c->leftChild = b;
				c->rightChild = a;
				switch (c->bf) 
				{
				case 1:
					a->bf = -1;
					b->bf = 0;
					break;
				case -1:
					b->bf = 1;
					a->bf = 0;
					break;
				case 0:
					a->bf = 0;
					b->bf = 0;
					break;
				}
				c->bf = 0;
				b = c;
			}
		}
		else
		{
			if (b->bf == -1)
			{
				b->rightChild = a->leftChild;
				a->leftChild = b;
				a->bf = 0;
				b->bf = 0;
			}
			else
			{
				c = a->leftChild;
				a->leftChild = c->rightChild;
				b->rightChild = c->leftChild;
				c->rightChild = b;
				c->leftChild = a;
				switch (c->bf)
				{
				case 1:
					a->bf = -1;
					b->bf = 0;
					break;
				case -1:
					b->bf = 1;
					a->bf = 0;
					break;
				case 0:
					a->bf = 0;
					b->bf = 0;
					break;
				}
				c->bf = 0;
				b = c;
			}
		}

		if (!pa)
			root = b;
		else if (a == pa->leftChild)
			pa->leftChild = b;
		else
			pa->rightChild = b;

	}
}
