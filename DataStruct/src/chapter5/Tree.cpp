#include "chapter5/Tree.h"
#include <iostream>

using namespace std;

namespace Chapter5
{
	template <class T>
	Tree<T>::Tree()
	{
		root = nullptr;
	}

	template <class T>
	Tree<T>::Tree(const Tree<T>& s)
	{
		root = Copy(s.root);
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
		else
			InsertEmpty(root, x);
	}

	template<class T>
	bool Tree<T>::InsertEmpty(TreeNode<T>* t, TreeNode<T>* x)
	{
		if (!t->leftChild)
		{
			t->leftChild = x;
			return true;
		}
		if (!t->rightChild)
		{
			t->rightChild = x;
			return true;
		}

		if (InsertEmpty(t->leftChild, x))
			return true;
			
		return InsertEmpty(t->rightChild, x);
	}

	template <class T>
	int Tree<T>::Count()
	{
		return Count(root);
	}

	template <class T>
	int Tree<T>::Count(TreeNode<T>* node)
	{
		if (!node)
			return 0;
		return 1 + Count(node->leftChild) + Count(node->rightChild);
	}

	template <class T>
	void Tree<T>::SwapTree()
	{
		return SwapTree(root);
	}

	template <class T>
	void Tree<T>::SwapTree(TreeNode<T>* node)
	{
		if (node->leftChild)
			SwapTree(node->leftChild);
		if (node->rightChild)
			SwapTree(node->rightChild);

		TreeNode<T>* temp = node->leftChild;
		node->leftChild = node->rightChild;
		node->rightChild = temp;
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
	void Tree<T>::Visit(TreeNode<T>* currentNode)
	{
		cout << currentNode->data << " ";
	}

	template<class T>
	void Tree<T>::Copy(TreeNode<T>* originNode)
	{
		if (!originNode)
			return nullptr;
		return new TreeNode<T>(
			originNode->data,
			Copy(originNode->leftChild),
			Copy(originNode->rightChild));
	}

	template<class T>
	void Tree<T>::Equal(TreeNode<T> *a, TreeNode<T> *b)
	{
		if ((!a) && (!b))
			return true;
		return (a && b
			&& (a->data == b->data)
			&& Equal(a->rightChild, b->rightChild)
			&& Equal(a->leftChild, b->leftChild));
	}

	void TreeTest()
	{
		Tree<int> t;

		t.Insert(new TreeNode<int>(1));
		t.Insert(new TreeNode<int>(2));
		t.Insert(new TreeNode<int>(3));
		t.Insert(new TreeNode<int>(4));
		t.Insert(new TreeNode<int>(5));
		t.Insert(new TreeNode<int>(6));
		t.Insert(new TreeNode<int>(7));

		t.LevelOrder();
		cout << endl;

		t.Inorder();
		cout << endl;

		t.SwapTree();
		t.LevelOrder();
		cout << t.Count();
	}
}
