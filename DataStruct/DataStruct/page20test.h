#pragma once
#include <string>

using namespace std;

namespace Chapter1 {

	class Page20test
	{
	public:
		void DivZero(int _a, int _b, int _c);
	private:
		int a, b, c;
	};

	void GetDivZeroInput();
	int* GetArrayInput();

	void AddArray();
	void AddArray(int n, int a);

	void BinarySearch();
	int BinarySearch(int* _a, const int _t, int _left, int _right);
	
	void Permutations();
	string Permutations(char *_a, const int _t, const int _m);
}

