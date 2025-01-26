#pragma once
#include <iostream>

using namespace std;

namespace Chapter2 {

	class Currency
	{
	public:
		Currency();
		Currency(int _d = 0, int _c = 0);
		Currency(float cur = 0);
		~Currency();

		Currency operator+(const float a);
		Currency operator-(const float a);
		Currency operator*(const float a);
		friend ostream& operator<<(ostream& os, const Currency& c);
		friend istream& operator>>(istream& os, Currency& c);
	private:
		int dollar;
		int cent;
	};

	void CalcCurrency();
}
