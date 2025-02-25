#include "chapter3/Bag.h"
#include "chapter3/ChangeSize.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace Chapter3
{
	template <class T>
	Bag<T>::Bag()
	{

	}

	template <class T>
	Bag<T>::Bag(int bagCapacity)
		: capacity(bagCapacity)
	{
		if (capacity < 1)
		{
			cout << "Capacity below 1" << endl;
			return;
		}

		array = new T[capacity];
		top = -1;
	}

	template <class T>
	Bag<T>::~Bag()
	{

	}

	template <class T>
	int Bag<T>::Size() const
	{
		return top + 1;
	}

	template <class T>
	bool Bag<T>::IsEmpty() const
	{
		return Size() == 0;
	}

	template <class T>
	T& Bag<T>::Element() const
	{
		if (IsEmpty())
			throw "Bag is Empty";

		return array[0];
	}

	template <class T>
	void Bag<T>::Push(const T& p)
	{
		if (capacity == top + 1)
		{
			ChangeSize1D(array, capacity, 2 * capacity);
			capacity *= 2;
		}
		array[++top] = p;
	}

	template <class T>
	void Bag<T>::Pop()
	{
		if (IsEmpty())
		{
			cout << "Bag is empty, cannot delete" << endl;
			return;
		}
		int deletePos = top / 2;
		copy(array + deletePos + 1, array + top + 1, array + deletePos);
		array[top--].~T();
	}

	void ModifyBag()
	{
		Bag<int> bag(3);

		bag.Push(10);
		bag.Push(5);

		cout << bag.Element() << endl;
		bag.Pop();
		cout << bag.Element() << endl;

		bag.Pop();
		bag.Pop();
	}
}