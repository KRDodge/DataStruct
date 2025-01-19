#include "page20test.h"
#include <iostream>
#include <vector>
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

	int GetArraySize()
	{
		int n = 0;
		cout << "배열 개수 n:";
		cin >> n;
		return n;
	}

	int* GetIntArrayInput(int n) 
	{
		int* arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		return arr;
	}

	char* GetCharArrayInput(int n)
	{
		char* arr = new char[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		return arr;
	}

	void AddArray()
	{
		int n = GetArraySize();
		int* arr = GetIntArrayInput(n);
		int a;

		cout << "~ 까지 더할 인덱스 a:";
		cin >> a;

		AddArray(arr, a);
		delete[] arr;
	}

	void AddArray(int* arr, int a)
	{
		int sum = 0;
		for (int i = 0; i < a; ++i)
		{
			sum += arr[i];
		}

		cout << sum << endl;
	}

	void BinarySearch()
	{
		int n = GetArraySize();
		int* arr = GetIntArrayInput(n);

		int a;
		cout << "찾을 수 a:";
		cin >> a;

		int res = BinarySearch(arr, a, 0, n);

		cout << res << endl;
		delete[] arr;
	}

	int BinarySearch(int* _a, const int _t, int _left, int _right)
	{
		int middle = (_left + _right) / 2;
		if (_t < _a[middle])
			return BinarySearch(_a, _t, _left, middle - 1);
		else if (_t > _a[middle])
			return BinarySearch(_a, _t, middle + 1, _right);
		else if (_t == _a[middle])
			return middle;
		return -1;
	}

	void Permutations()
	{
		int n = GetArraySize();
		char* arr = GetCharArrayInput(n);
		Permutations(arr, 0, n);
	}

	void Permutations(char* _a, const int _k, const int _m)
	{
		if (_k == _m)
		{
			for (int i = 0; i <= _m; i++)
				cout << _a[i] << " ";
			cout << endl;
		}
		else
		{
			for (int i = _k; i < _m; ++i)
			{
				swap(_a[_k], _a[i]);
				Permutations(_a, _k + 1, _m);
				swap(_a[_k], _a[i]);
			}
		}
	}
}
