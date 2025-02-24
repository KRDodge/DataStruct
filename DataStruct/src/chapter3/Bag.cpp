#include "chapter3/Bag.h"
#include "chapter3/ChangeSize.h"
#include <algorithm>

using namespace std;

namespace Chapter3
{
	Bag::Bag()
	{

	}

	Bag::Bag(int bagCapacity) 
		: capacity(bagCapacity)
	{
		if (capacity < 1)
			throw "Capacity below 1";

		array = new int[capacity];
		top -= 1;
	}

	Bag::~Bag()
	{

	}

	int Bag::Size() const
	{
		return top + 1;
	}

	bool Bag::IsEmpty() const
	{
		return Size() == 0;
	}

	int Bag::Element() const
	{
		if (IsEmpty())
			throw "Bag is Empty";
		return array[0];
	}

	void Bag::Push(const int p)
	{
		if (capacity == top + 1)
			ChangeSize1D(array, capacity, 2 * capacity);

		capacity *= 2;
		array[++top] = p;
	}

	void Bag::Pop()
	{
		if (IsEmpty())
			throw "Bag is empty, cannot delete";
		int deletePos = top / 2;
		copy(array + deletePos + 1, array + top + 1, array + deletePos);
		top--;
	}

	void ModifyBag()
	{
	}
}