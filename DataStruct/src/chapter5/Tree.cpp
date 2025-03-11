#include "chapter5/Tree.h"

namespace Chapter5
{
	template <class T>
	Tree<T>::Tree()
	{
	}

	template <class T>
	Tree<T>::~Tree()
	{
	}
	
	template <class T>
	void Tree<T>::Insert(TreeNode<T>* x)
	{
		if (!root)
			root = x;
		
		TreeNode<T>* current = x;
		bool inserted = false;
		inserted = InsertEmpty(current, x);

	}

	template<class T>
	bool Tree<T>::InsertEmpty(TreeNode<T>* t, TreeNode<T>* x)
	{
		if (!t->leftChild)
		{
			t->leftChild = x;
			return true;
		}
		else
			InsertEmpty(t->leftChild);
		
		if (!t->rightChild)
		{
			t->rightChild = x;
			return true;
		}

		if (InsertEmpty(t->rightChild))
			return true;
			
		return InsertEmpty(t->rightChild, x);
	}
}
