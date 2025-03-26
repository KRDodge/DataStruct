#pragma once
#include "chapter5/MinPQ.h"
#include <iostream>
#include <queue>

using namespace std;
using namespace Chapter5;

namespace Chapter9
{
	template <class T> class MinLeftistTree;

	template <class T>
	class LeftistNode
	{
	public:
		friend class MinLeftistTree<T>;
		LeftistNode(T d) : data(d) { LeftChild = nullptr; RightChild = nullptr; };

		T data;
		LeftistNode* LeftChild;
		LeftistNode* RightChild;
		int shortest;
	};

	template <class T>
	class MinLeftistTree : public MinPQ<T> 
	{
	public:
		MinLeftistTree(LeftistNode<T>* init = 0) : root(init) {};

		bool IsEmpty() const override;
		const T& Top() const override;
		void Pop() override;
		void Push(const T& p) override;

		const T& GetMin() const;
		void Insert(const T&);
		T& DeleteMin();
		void Meld(MinLeftistTree<T>* b);
		LeftistNode<T>* GetRoot() { return root; }

		template <class T>
		friend ostream& operator<<(ostream& os, const MinLeftistTree<T>& t)
		{
			if (t.root == nullptr)
				return os;

			queue<LeftistNode<T>*> q;
			q.push(t.root);
			while (!q.empty())
			{
				LeftistNode<T>* val = q.front();
				q.pop();

				if (val == nullptr)
					continue;

				os << val->data << " ";
				q.push(val->LeftChild);
				q.push(val->RightChild);
			}
			return os;
		}

	private:
		LeftistNode<T>* root;
		LeftistNode<T>* Meld(LeftistNode<T>* a, LeftistNode<T>* b);
	};

	void TestLeftistTree();
}