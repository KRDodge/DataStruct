#include "chapter1/page27test.h"
#include <iostream>
#include <vector>

using namespace std;


namespace Chapter1 {
	void Horner()
	{

	}

	void AllBool()
	{
		int n;
		cin >> n;

		bool* _arr = new bool[n];
		FindAllBool(_arr, n, 0);
	}

	void FindAllBool(bool* b, int _n, int index)
	{
		if (index == _n)
		{
			for (int i = 0; i < _n; ++i)
			{
				cout << (b[i] ? "false" : "true") << " ";
			}
			cout << endl;
			return;
		}

		b[index] = false;
		FindAllBool(b, _n, index + 1);

		b[index] = true;
		FindAllBool(b, _n, index + 1);
	}

	void Fibonacci()
	{
		int a;
		cin >> a;

		int res = Fibonacci(a, 0, 0, 1);
		cout << res << endl;
	}

	//int Fibonacci(int _n)
	//{
	//	int res = 0;
	//	int prev = 0;
	//	int prevprev = 1;
	//	for (int i = 0; i < _n; ++i)
	//	{
	//		res = prev + prevprev;
	//		prevprev = prev;
	//		prev = res;
	//	}

	//	cout << res << endl;
	//	return res;
	//}

	int Fibonacci(int _n, int _count, int _a, int _b)
	{
		int res = _a + _b;
		if (_count == _n)
			return res;
		else
			res = Fibonacci(_n, ++_count, _b, res);
		return res;
	}

	int Fibonacci(int n)
	{
		if (n <= 1)
			return n;
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
