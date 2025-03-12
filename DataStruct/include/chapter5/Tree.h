#pragma once
#include "chapter3/Stack.h"
#include "chapter3/Queue.h"

using namespace Chapter3;

namespace Chapter5
{
	template <class T> class Tree;
	
	template<class T>
	class TreeNode
	{
	public:
		friend class Tree<T>;
		TreeNode(T d) : data(d), leftChild(nullptr), rightChild(nullptr) {}
		TreeNode(T d, TreeNode<T>* l, TreeNode<T> r) :
			data(d), leftChild(l), rightChild(r) {}
	protected:
		T data;
		TreeNode<T>* leftChild;
		TreeNode<T>* rightChild;
	};

	template <class T>
	class Tree
	{
	public:
		Tree();
		Tree(const Tree<T>& s);
		~Tree();

		void Insert(TreeNode<T>* x);
		bool InsertEmpty(TreeNode<T>* l, TreeNode<T>* x);
		
		int Count();
		int Count(TreeNode<T>* n);
		
		void SwapTree();
		void SwapTree(TreeNode<T>* n);

		void Inorder();
		void Inorder(TreeNode<T>* currentNode);

		void NonrecInorder();

		void Preorder();
		void Preorder(TreeNode<T>* currentNode);

		void Postorder();
		void Postorder(TreeNode<T>* currentNode);

		void LevelOrder()
		{
			Queue<TreeNode<T>*> q(10);
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

		void Visit(TreeNode<T>* currentNode);
		void Copy(TreeNode<T>* origin);
		void Equal(TreeNode<T> *a, TreeNode<T> *b);

		bool operator==(const Tree& t) const
		{
			return Equal(root, t.root);
		}

	private:
		TreeNode<T>* root;
	};

	void TreeTest();
}