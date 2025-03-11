#pragma once

namespace Chapter5
{
	template <class T>
	class BinaryTree
	{
	public:
		BinaryTree();
		BinaryTree(BinaryTree<T>& bt1, T& item, BinaryTree<T>& bt2);

		bool IsEmpty();
		BinaryTree<T> LeftSubtree();
		BinaryTree<T> RightSubtree();
		T RootData();

	};
}

