#pragma once
#include <iostream>

using namespace std;

namespace Chapter3
{
	enum Direction
	{
		N = 0,
		NE,
		E,
		SE,
		S,
		SW,
		W,
		NW,
	};

	struct Items
	{
		Items(int _x, int _y, Direction _dir) : x(_x), y(_y), dir(_dir) {}
		Items() : x(1), y(1), dir(Direction::N) {}

		int x, y;
		Direction dir;

		friend std::ostream& operator<<(std::ostream& os, const Items& item)
		{
			os << "(" << item.x << ", " << item.y << ", " << item.dir << ")";
			return os;
		}
	};

	struct Offsets
	{
		int a, b;
	};

	template <class T>
	class Stack
	{
	public:
		Stack();
		Stack(int bagCapacity);
		~Stack();

		int Size() const;
		bool IsEmpty() const;
		T& Element() const;
		T& Top() const;

		void Push(const T& p);
		void Pop();

	private:
		T* array;
		int capacity;
		int top;

	};

	void ModifyBag();
	void MazeDFS(const int m, const int p);
}