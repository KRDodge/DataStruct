#include "chapter7/Sort.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace Chapter7
{
	template <class T>
	Sort<T>::Sort()
	{
		d = new list<T>();
	}

	template<class T>
	Sort<T>::~Sort()
	{
		delete d;
	}

	template<class T>
	int Sort<T>::BinarySearch(T* a, T key, int low, int high)
	{
		while (low <= high) 
		{
			int mid = (low + high) / 2;
			if (key < a[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		return low;
	}

	template<class T>
	int Sort<T>::BinarySearchList(list<T> a, T key, int low, int high)
	{
		while (low <= high)
		{
			int mid = (low + high) / 2;
			if (key < a[mid])
				high = mid - 1;
			else
				low = mid + 1;
		}
		return low;
	}

	template<class T>
	void Sort<T>::Insert(const T& e, T* a, int i)
	{
		//교재에서는 a[0]를 루프 검사를 더 쉽게 하기 위해 더미 스페이스로 사용하고 있던데
		//해당 알고리즘 내에서만 더 효율적이지 외부에서 접근했을 때 0인덱스를 못쓰는 문제 발생 (외부에서 0인덱스가 더미인지를 모름)
		int loc = BinarySearch(a, e, 0, i);
		while (i >= loc) 
		{
			a[i + 1] = a[i];
			i--;
		}
		a[loc] = e;
	}

	template<class T>
	void Sort<T>::InsertList(const T& e, list<T> a, int i)
	{
		int loc = BinarySearchList(a, e, 0, i);
		while (i >= 0) 
		{
			a[i + 1] = a[i];
			i--;
		}
		a[loc] = e;
	}

	template<class T>
	void Sort<T>::InsertionSort(T* a, const int n)
	{
		for (int i = 1; i < n; ++i) 
		{
			T key = a[i];
			Insert(key, a, i - 1);
		}
	}

	template<class T>
	void Sort<T>::InsertionSort(list<T>* a)
	{
		int n = a->size();
		for (int i = 1; i < n; ++i) 
		{
			T key = a[i];
			InsertList(key, *a, i - 1);
		}
	}
	template<class T>
	void Sort<T>::QuickSort(T* a, const int left, const int right)
	{
		if (left >= right)
			return;

		int i = left;
		int j = right;
		T pivot = a[left];
		while (i < j)
		{
			while (i < j && a[j] >= pivot)
				j--;
			while (i < j && a[i] <= pivot)
				i++;

			if (i < j)
				swap(a[i], a[j]);
		}
		swap(a[left], a[i]);

		QuickSort(a, left, i - 1);
		QuickSort(a, i + 1, right);
	}

	template<class T>
	void Sort<T>::MergeSort(T* a, const int n)
	{
		T* tempList = new T[n + 1];
		for (int i = 1; i < n; i *= 2)
		{
			MergePass(a, tempList, n, i);
			i *= 2;
			MergePass(tempList, a, n, i);
		}
		delete[] tempList;
	}

	template<class T>
	int Sort<T>::rMergeSort(T* a, int* link, const int left, const int right)
	{
		if (left >= right)
			return left;

		int mid = (left + right) / 2;
		return ListMerge(a, link, rMergeSort(a, link, left, mid), rMergeSort(a, link, mid + 1, right));
	}

	template<class T>
	int Sort<T>::ListMerge(T* a, int* link, const int start1, const int start2)
	{
		int iResult = 0;
		int i1, i2;
		for (i1 = start1, i2 = start2; i1 && i2; )
		{
			if (a[i1] <= a[i2])
			{
				link[iResult] = i1;
				iResult = i1;
				i1 = link[i1];
			}
			else
			{
				link[iResult] = i2;
				iResult = i2;
				i2 = link[i2];
			}
		}
		if (i1 == 0)
			link[iResult] = i2;
		else
			link[iResult] = i1;
		return link[0];
	}

	template<class T>
	void Sort<T>::MergePass(T* initList, T* resultList, const int n, const int s)
	{
		int  i = 1;
		for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
			Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);

		if ((i + s - 1) < n)
			Merge(initList, resultList, i, i + s - 1, n);
		else
			copy(initList + i, initList + n + 1, resultList + i);
	}

	template<class T>
	void Sort<T>::Merge(T* initList, T* mergedList, const int l, const int m, const int n)
	{
		int i1 = l;
		int i2 = m + 1;
		int iResult = l;

		while (i1 <= m && i2 <= n) 
		{
			if (initList[i1] <= initList[i2])
				mergedList[iResult++] = initList[i1++];
			else
				mergedList[iResult++] = initList[i2++];
		}

		while (i1 <= m)
			mergedList[iResult++] = initList[i1++];
		while (i2 <= n)
			mergedList[iResult++] = initList[i2++];
	}

	void TestSort()
	{
		Sort<int> sort;

		int n = 10;
		int* a = new int[10];
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		
		cout << endl;
		//sort.QuickSort(a, 0, 9);
		//sort.InsertionSort(a, 10);
		sort.MergeSort(a, 10);
		for (int i = 0; i < n; ++i)
			cout << a[i] << " ";

	}
}