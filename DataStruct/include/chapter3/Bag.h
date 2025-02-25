#pragma once

namespace Chapter3
{
	template <class T>
	class Bag
	{
	public:
		Bag();
		Bag(int bagCapacity);
		~Bag();

		int Size() const;
		bool IsEmpty() const;
		T& Element() const;
		
		void Push(const T& p);
		void Pop();

	private:
		T* array;
		int capacity;
		int top;

	};

	void ModifyBag();
}