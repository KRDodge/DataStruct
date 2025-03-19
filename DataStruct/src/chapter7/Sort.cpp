#include "chapter7/Sort.h"

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
		delete list;
	}

	template<class T>
	void Sort<T>::Insert(const T& e, T* a, int i)
	{
		a[0] = e;
		while (e < a[i])
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = e;
	}

	template<class T>
	void Sort<T>::InsertionSort(T* a, const int n)
	{
		for (int j = 2; j <= n; ++j)
		{
			T temp = a[j];
			Insert(temp, a, j - 1);
		}
	}
}