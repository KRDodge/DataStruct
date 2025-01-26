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
		friend istream& operator>>(istream& os, const Currency& c);
	private:
		int dollar;
		int cent;
	};

	ostream& operator<<(ostream& os, const Currency& c)
	{
		os << "$" << c.dollar << ".";
		if (c.cent < 10)
			os << "0";
		os << c.cent;
		return os;
	}

	istream& operator>>(istream& is, const Currency& c)
	{
		is >> c.dollar >> c.cent;
		return is;
	}

	void CalcCurrency();
}
