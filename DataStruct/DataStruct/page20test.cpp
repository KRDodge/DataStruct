#include "page20test.h"
#include <iostream>
using namespace std;


namespace Chapter1 {

	void Page20test::DivZero(int _a, int _b, int _c)
	{
		int res = 0;
		try {
			if (_a < 0 && _b < 0 && _c < 0)
			{
				cout << 1 << endl;
				return;
			}
			else if (a == 0 || b == 0 || c == 0)
			{
				cout << 2 << endl;
				return;
			}
			res = _a + _b * _c + _b / _c;
			cout << res << endl;
		}
		catch(char* e)
		{
			cout << "div by zero error" << endl;
			cout << e << endl;
		}
	}

	void GetDivZeroInput()
	{
		cout << "3개 수 입력" << endl;

		int a, b, c;
		cin >> a >> b >> c;

		Page20test test;
		test.DivZero(a, b, c);
	}

	void GetArrayInput() 
	{
		int n;
		int a;
		cout << "배열 개수 n:";
		cin >> n;

		cout << "~ 까지 더할 인덱스 a:";
		cin >> a;

		AddArray(n, a);
	}

	void AddArray(int n, int a)
	{
		if (a > n)
		{
			cout << "index is bigger than n" << endl;
		}
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		int sum = 0;
		for (int i = 0; i < a; ++i)
		{
			sum += arr[i];
		}

		cout << sum << endl;

		delete[] arr;
	}
}
