#include "memory.h"
#include "stl.h"
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

namespace Chapter1 {

	void Product()
	{
		int n = 0;
		cin >> n;

		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int res = Product(arr, n);
		cout << res << endl;
	}

	int Product(int* a, int n)
	{
		int init = 1;
		return accumulate(a, a+n, init, multiplies<int>());
	}

	void Copy()
	{
		int *arr = new int[3];
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 3;

		cout << arr << endl;
		int b = 0;

		int* barr = new int[3];
		cout << barr << endl;

		copy(arr,arr + 3, barr);
		for (int i = 0; i < 3; i++) {
			cout << barr[i] << " ";
		}
		
		delete[] arr;
		delete[] barr;
	}

	void NPermutations()
	{
		int n;
		cin >> n;
		char* arr = new char[n];

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		/*do
		{
			copy(arr, arr + n, ostream_iterator<char>(cout, ""));
			cout << endl;
		}
		while (next_permutation(arr, arr + n));*/
		bool hasNext = true;
		while (hasNext)
		{
			copy(arr, arr + n, ostream_iterator<char>(cout, ""));
			cout << endl;

			hasNext = next_permutation(arr, arr + n);
		}

		delete[] arr;
	}

	void MagicSquare()
	{
		int n;
		cin >> n;

		int square[51][51], k, l;

		if (n >= 51 || n < 1)
			return;

		if (!(n % 2))
			return;

		for (int i = 0; i < n; ++i)
		{
			fill(square[i], square[i] + n, 0);
		}
		square[0][(n - 1) / 2] = 1;

		int key = 2;
		int i = 0;
		int j = (n - 1) / 2;

		while (key <= n * n)
		{
			if (i - 1 < 0)
				k = n - 1;
			else
				k = i - 1;

			if (j - 1 < 0)
				l = n - 1;
			else
				l = j - 1;
			if (square[k][l])
				i = (i + 1) % n;
			else
			{
				i = k;
				j = l;
			}
			square[i][j] = key;
			key++;
		}

		for (i = 0; i < n; i++)
		{
			copy(square[i], square[i] + n, ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}

	void SeqSearchTime()
	{
		int a[1001], n[20];

		for (int i = 1; i < 1000; ++i)
			a[i] = i;
		
		for (int i = 0; i < 10; ++i)
		{
			n[i] = 10 * i;
			n[i + 10] = 100 * (i + 1);
		}

		cout << "n time" << endl;

		for (int i = 0; i < 20; ++i)
		{
			time_t start, stop;
			time(&start);
			int k = SequentialSearch(a, n[i], 0);
			time(&stop);
			long runtime = stop - start;
			cout << " " << n[i] << runtime << endl;
		}
	}

	int SequentialSearch(int *a, const int n, const int x)
	{
		for (int i = 0; i < n; ++i)
		{
			if (a[i] == x)
			{
				if (i == n)
					return -1;
				return i;
			}
		}
		return -1;
	}
}
