#pragma once
#include "chapter3/Stack.h"
#include "Tree.h"

using namespace Chapter3;

namespace Chapter5
{
	template <class T>
	class PreorderIterator
	{
	public:
		PreorderIterator()
		{
			currentNode = root;
			if (currentNode)
				s.Push(currentNode);
		}

		T* Next()
		{
			if (s.IsEmpty())
				return nullptr;

			currentNode = s.Top();
			s.Pop();

			if (currentNode->rightChild)
				s.Push(currentNode->rightChild);
			if (currentNode->leftChild)
				s.Push(currentNode->leftChild);

			return &currentNode->data;
		}

	private:
		Stack<TreeNode<T>*> s;
		TreeNode<T>* currentNode;
		TreeNode<T>* parentNode;
	};
}
