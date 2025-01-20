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
}
