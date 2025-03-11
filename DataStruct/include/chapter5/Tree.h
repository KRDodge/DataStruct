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
		friend class Tree<T>;
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
		~Tree();

		void Insert(TreeNode<T>* x);
		bool InsertEmpty(TreeNode<T>* l, TreeNode<T>* x);

		void Inorder();
		void Inorder(TreeNode<T>* currentNode);

		void NonrecInorder();

		void Preorder();
		void Preorder(TreeNode<T>* currentNode);

		void Postorder();
		void Postorder(TreeNode<T>* currentNode);

		void LevelOrder();

		void Visit(TreeNode<T>* currentNode);

	private:
		TreeNode<T>* root;
	};
}

