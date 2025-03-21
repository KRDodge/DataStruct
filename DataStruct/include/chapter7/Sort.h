#pragma once
#include <list>

using namespace std;

namespace Chapter7
{
	template <class T>
	class Sort
	{
	public:
		Sort();
		~Sort();

		int BinarySearch(T* a, T key, int low, int high);

		int BinarySearchList(list<T> a, T key, int low, int high);

		void Insert(const T& e, T* a, int i);
		void InsertList(const T& e, list<T> a, int i);
		void InsertionSort(T* a, const int n);
		void InsertionSort(list<T>* a);

		void QuickSort(T* a, const int left, const int right);

		void MergeSort(T* a, const int n);
		void MergePass(T* initList, T* resultList, const int n, const int s);
		void Merge(T* initList, T* mergedList, const int l, const int m, const int n);

		int rMergeSort(T* a, int* link, const int left, const int right);
		int ListMerge(T* a, int* link, const int start1, const int start2);

		void HeapSort(T* a, const int n);
		void Adjust(T* a, const int root, const int n);

	private:
		list<T>* d; //이제 list 쓰자 vector는 위치 교환 및 삽입 연산 여러번 일어나서 비효율적
	};

	void TestSort();
}