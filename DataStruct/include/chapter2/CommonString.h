#pragma once
#include <iostream>

using namespace std;

namespace Chapter2 
{
	class CommonString
	{
	public:
		CommonString();
		CommonString(char* init, int m);
		~CommonString();

		bool operator==(CommonString t);
		bool operator!();

		int Length();

		CommonString Concat(CommonString t);
		CommonString Substr(int i, int j);
		int Find(CommonString pat);
		int FastFind(CommonString pat);

	private:
		int length;
		char* string;
	};

	void SparseMatrixInput();
}
