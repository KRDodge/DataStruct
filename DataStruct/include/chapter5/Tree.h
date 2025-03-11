#pragma once

namespace Chapter5
{
	template <class T> class Tree;
	

	template<class T>
	class TreeNode
	{
		friend class Tree<T>;

	private:
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

	private:
		private TreeNode<T>* root;
	};
}

