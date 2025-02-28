#include "chapter3/Stack.h"
#include "chapter3/ChangeSize.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace Chapter3
{
	template <class T>
	Stack<T>::Stack()
	{

	}

	template <class T>
	Stack<T>::Stack(int bagCapacity)
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
	Stack<T>::~Stack()
	{

	}

	template <class T>
	int Stack<T>::Size() const
	{
		return top + 1;
	}

	template <class T>
	bool Stack<T>::IsEmpty() const
	{
		return Size() == 0;
	}

	template <class T>
	T& Stack<T>::Element() const
	{
		if (IsEmpty())
			throw "Stack is Empty";

		return array[0];
	}

	template <class T>
	T& Stack<T>::Top() const
	{
		if (IsEmpty())
			throw "Stack is Empty";

		return array[top];
	}

	template <class T>
	void Stack<T>::Push(const T& p)
	{
		if (capacity == top + 1)
		{
			ChangeSize1D(array, capacity, 2 * capacity);
			capacity *= 2;
		}
		array[++top] = p;
	}

	template <class T>
	void Stack<T>::Pop()
	{
		if (IsEmpty())
		{
			cout << "Stack is empty, cannot delete" << endl;
			return;
		}
		int deletePos = top / 2;
		copy(array + deletePos + 1, array + top + 1, array + deletePos);
		array[top--].~T();
	}

	void ModifyBag()
	{
		Stack<int> bag(3);

		bag.Push(10);
		bag.Push(5);

		cout << bag.Element() << endl;
		bag.Pop();
		cout << bag.Element() << endl;

		bag.Pop();
		bag.Pop();
	}

	void MazeDFS(const int m, const int p)
	{
		bool mark[100][100];
		bool maze[100][100];
		Offsets move[8];

		mark[1][1] = 1;
		Stack<Items> stack(m * p);

		Items temp(1, 1, Direction::E);

		stack.Push(temp);
		while (!stack.IsEmpty())
		{
			temp = stack.Top();
			stack.Pop();
			int i = temp.x;
			int j = temp.y;
			int d = temp.dir;

			while (d < 8)
			{
				int g = i + move[d].a;
				int h = j + move[d].b;
				if ((g == m) && (h == p))
				{
					cout << stack.Top() << endl;
					cout << i << " " << j << endl;
					cout << m << " " << p << endl;
					return;
				}
				if (!maze[g][h] && !mark[g][h])
				{
					mark[g][h] = 1;
					temp.x = i;
					temp.y = j;
					temp.dir = Direction(d + 1);
					stack.Push(temp);

					i = g;
					j = h;
					d = Direction::N;
				}
				else
					d++;
			}

			cout << "No path" << endl;
		}
	}
}