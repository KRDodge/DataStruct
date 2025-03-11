#pragma once
#include "chapter3/Stack.h"
#include "Tree.h"

using namespace Chapter3;

namespace Chapter5
{
	template <class T>
	class PostorderIterator
	{
	public:
		PostorderIterator()
		{
			currentNode = root;
			if (currentNode)
				s.Push(currentNode);
		}

		T* Next()
		{
			while (currentNode || !s.IsEmpty())
			{
				while (currentNode) {
					s.Push(currentNode);
					currentNode = currentNode->leftChild;
				}

				TreeNode<T>* temp = s.Top();
				if (temp->rightChild && temp->rightChild != lastVisited) 
					currentNode = temp->rightChild;
				else 
				{
					s.Pop();
					lastVisited = temp;
					return &(temp->data);
				}
			}
			return nullptr;
		}

	private:
		Stack<TreeNode<T>*> s;
		TreeNode<T>* currentNode;
		TreeNode<T>* parentNode;
	};
}
