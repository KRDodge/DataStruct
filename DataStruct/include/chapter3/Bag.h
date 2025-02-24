#pragma once

namespace Chapter3
{
	class Bag
	{
	public:
		Bag();
		Bag(int bagCapacity);
		~Bag();

		int Size() const;
		bool IsEmpty() const;
		int Element() const;
		void Push(const int p);
		void Pop();

	private:
		int* array;
		int capacity;
		int top;

	};

	void ModifyBag();
}