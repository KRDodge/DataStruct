#pragma once
#include <list>

using namespace std;

namespace Chapter7
{
	template <class T>
	class Sort
	{
		Sort();
		~Sort();
		void Insert(const T& e, T* a, int i);
		void InsertionSort(T* a, const int n);

	private:
		list<T> d; //이제 list 쓰자 vector는 위치 교환 및 삽입 연산 여러번 일어나서 비효율적
	};
}