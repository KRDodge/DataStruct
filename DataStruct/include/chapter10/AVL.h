#pragma once
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

namespace Chapter10
{
	template <class K, class E> class AVL;

	template<class K, class E>
	class AvlNode 
	{
	public:
		friend class AVL<K, E>;
		AvlNode(const K& k, const E& e)
		{
			key = k;
			element = e;
			bf = 0;
			leftChild = rightChild = 0;
		};
		E& GetElement() { return element; };
		AvlNode<K, E>* Left() { return leftChild; };
		AvlNode<K, E>* Right() { return rightChild; };
	private:
		K key;
		E element;
		int bf;
		AvlNode<K, E>* leftChild;
		AvlNode<K, E>* rightChild;
	};

	template <class K, class E>
	class AVL 
	{
	public:
		AVL() : root(nullptr) {};
		E& Search(const K&) const;
		void Insert(const K&, const E&);
		void Delete(const K&);
		bool IsEmpty() const;

		template <class K, class E>
		friend ostream& operator<<(ostream& os, const AVL<K, E>& a)
		{
			if (a.IsEmpty())
				return os;
			
			//queue<AvlNode<K, E>*> q = a.root;
			
			/*q.push(a.root);

			AvlNode<K, E>* front;

			while (!q.empty())
			{
				front = q.front();
				if(front->Left())
					q.push(front->Left());
				if(front->Right())
					q.push(front->Right());
				os << front->GetElement() << " ";
				q.pop();
			}*/

			stack<AvlNode<K, E>*> s;
			AvlNode<K, E>* current = a.root;

			while (current || !s.empty()) {
				while (current) {
					s.push(current);
					current = current->Left();
				}

				current = s.top();
				s.pop();

				os << current->GetElement() << " ";
				current = current->Right();
			}
			return os;
		}

	private:
		AvlNode<K, E>* root;
	};

	void TestAVL();
}