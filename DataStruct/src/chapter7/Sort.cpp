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
		//교재에서는 a[0]를 루프 검사를 더 쉽게 하기 위해 더미 스페이스로 사용하고 있던데
		//해당 알고리즘 내에서만 더 효율적이지 외부에서 접근했을 때 0인덱스를 못쓰는 문제 발생 (외부에서 0가 더미인지를 모름)
		while (i >= 0 && a[i] > e) 
		{
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = e;
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
}