#pragma once
#include "chapter9/DEPQ.h"
#include "chapter3/ChangeSize.h"

using namespace Chapter3;

namespace Chapter9
{
	template <class T>
	class SMMH : public DEPQ
	{
		SMMH(int initialCapacity = 10)
		{
			if (initialCapacity < 1)
				throw "initialCapacity error";
			arrayLength = initialCapacity + 2;
			h = new T[arrayLength];
			last = 1;
		}

		~SMMH() { delete[] h; }

		const T& GetMin() const
		{
			if (last == 1)
				throw "queue is empty";
			return h[2];
		}

		const T& GetMax() const
		{
			if (last == 1)
				throw "queue is empty";
			if (last == 2)
				return h[2];
			return h[3];
		}

		void Insert(const T& x)
		{
			if (last == arrayLength - 1)
			{
				ChangeSize1D(h, arrayLength, 2 * arrayLength);
				arrayLength *= 2;
			}

			int currentNode = ++last;
			if (last % 2 == 1 && x < h[last - 1])
			{
				h[last] = h[last - 1];
				currentNode--;
			}

			bool done = false;
			while (!done && currentNode >= 4)
			{
				int gp = currentNode / 4;
				int lcgp = 2 * gp;
				int rcpg = lcgp + 1;
				if (x < h[lcgp])
				{
					h[currentNode] = h[lcgp];
					currentNode = lcgp;
				}
				else if (x > h[rcgp])
				{
					h[currentNode] = h[rcgp];
					currentNode = rcgp;
				}
				else
					done = true;
			}
			h[currentNode] = x;
		}

		void DeleteMin()
		{
			if (last == 1)
				throw "queue is empty";

			T lastElement = h[last--];
			if (last < 2) 
				return;

			int currentNode = 2;
			int child;

			while (2 * currentNode <= last)
			{
				int left = 2 * currentNode;
				int right = left + 1;

				if (right <= last && h[right] < h[left])
					child = right;
				else
					child = left;

				if (lastElement > h[child])
				{
					h[currentNode] = h[child];
					currentNode = child;
				}
				else
					break;
			}
			h[currentNode] = lastElement;
		}

		void DeleteMax() 
		{
			if (last == 1)
				throw "queue is empty";

			if (last == 2) 
			{
				--last;
				return;
			}

			T lastElement = h[last--];
			int currentNode = 3;
			int child;

			while (2 * currentNode <= last)
			{
				int left = 2 * currentNode;
				int right = left + 1;

				if (right <= last && h[right] > h[left])
					child = right;
				else
					child = left;

				if (lastElement < h[child])
				{
					h[currentNode] = h[child];
					currentNode = child;
				}
				else
					break;
			}
			h[currentNode] = lastElement;
		}


	private:
		int last;
		int arrayLength;
		T* h;

	};
}
