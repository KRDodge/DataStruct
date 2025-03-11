#include "chapter5/Tree.h"
#include <iostream>

using namespace std;

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

	template<class T>
	void Tree<T>::Inorder()
	{
		Inorder(root);
	}

	template<class T>
	void Tree<T>::Inorder(TreeNode<T>* currentNode)
	{
		if (currentNode)
		{
			Inorder(currentNode->leftChild);
			Visit(currentNode);
			Inorder(currentNode->rightChild);
		}
	}

	template<class T>
	void Tree<T>::NonrecInorder()
	{
		Stack<TreeNode<T>*> s;
		TreeNode<T>* currentNode = root;
		while (currentNode || !s.IsEmpty())
		{
			while (currentNode)
			{
				s.Push(currentNode);
				currentNode = currentNode->leftChild;
			}
			currentNode = s.Top();
			s.Pop();
			Visit(currentNode);
			currentNode = currentNode->rightChild;
		}
	}

	template<class T>
	void Tree<T>::Preorder()
	{
		Preorder(root);
	}

	template<class T>
	void Tree<T>::Preorder(TreeNode<T>* currentNode)
	{
		if (currentNode)
		{
			Visit(currentNode);
			Preorder(currentNode->leftChild);
			Preorder(currentNode->rightChild);
		}
	}

	template<class T>
	void Tree<T>::Postorder()
	{
		Postorder(root);
	}

	template<class T>
	void Tree<T>::Postorder(TreeNode<T>* currentNode)
	{
		if (currentNode)
		{
			Postorder(currentNode->leftChild);
			Postorder(currentNode->rightChild);
			Visit(currentNode);
		}
	}

	template<class T>
	void Tree<T>::LevelOrder()
	{
		Queue<TreeNode<T>*> q;
		TreeNode<T>* currentNode = root;
		while (currentNode)
		{
			Visit(currentNode);
			if (currentNode->leftChild)
				q.Push(currentNode->leftChild);
			if (currentNode->rightChild)
				q.Push(currentNode->rightChild);

			if (q.IsEmpty())
				return;
			currentNode = q.Front();
			q.Pop();
		}
	}

	template<class T>
	void Tree<T>::Visit(TreeNode<T>* currentNode)
	{
		cout << currentNode->data << " " << endl;
	}
}
