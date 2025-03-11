#pragma once
#include "chapter3/Stack.h"
#include "Tree.h"

using namespace Chapter3;

namespace Chapter5
{
	template <class T>
	class IndorderIterator
	{
	public:
		IndorerIterator()
		{
			currentNode = root;
		}

		T* Next()
		{
			while (currentNode)
			{
				s.Push(currentNode);
				currentNode = currentNode->leftChild;
			}
			if (s.IsEmpty())
				return 0;
			currentNode = s.Top();
			s.Pop();
			T& temp = currentNode->data;
			currentNode = currentNode->rightChild;
			return &temp;
		}

	private:
		Stack<TreeNode<T>*> s;
		TreeNode<T>* currentNode;
	};
}
