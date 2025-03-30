#pragma once
#include "chapter5/MinPQ.h"
#include <iostream>

using namespace Chapter5;
using namespace std;

namespace Chapter9
{
	template <class T> class BinomialHeap;

	template <class T>
	class BinomialNode
	{
		friend class BinomialHeap<T>;
	private:
		T data;
		BinomialNode<T>* child;
		BinomialNode<T>* link;
		int degree;
	};

	template <class T>
	class BinomialHeap : public MinPQ<T>
	{
	public:
		BinomialHeap(BinomialNode<T>* init = nullptr) : min(init) {};

		bool IsEmpty() const override;
		const T& Top() const override;
		void Pop() override;
		void Push(const T& p) override;

		const T& Min() const;
		void Insert(const T&);
		T& DeleteMin();
		void Meld(BinomialHeap<T>*);
		void Initialize() { min = nullptr; }
		BinomialNode<T>* GetMin() { return min; }

	private:
		BinomialNode<T>* min;
	};
}
