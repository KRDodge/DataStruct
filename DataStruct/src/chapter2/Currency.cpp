#include "chapter2/Rectangle.h"
#include "chapter2/Currency.h"
#include "chapter2/Currency.h"


namespace Chapter2
{
	Currency::Currency(int _d, int _c)
	{
		dollar = _d;
		cent = _c;
	}

	Currency::Currency(float cur)
	{
		dollar = (int)cur / 100;
		cent = (int)cur % 100;
	}

	Currency::Currency() : dollar(0), cent(0)
	{

	}

	Currency::~Currency()
	{

	}

	Currency Currency::operator+(const float a)
	{
		int totalCents = dollar * 100 + cent + static_cast<int>(a * 100);
		return Currency(totalCents / 100, totalCents % 100);
	}

	Currency Currency::operator-(const float a)
	{
		int totalCents = dollar * 100 + cent - static_cast<int>(a * 100);
		return Currency(totalCents / 100, totalCents % 100);
	}

	Currency Currency::operator*(const float a)
	{
		int res = (dollar * 100 + cent) * -static_cast<int>(a * 100);
		return Currency(res / 100, res % 100);
	}

	void CalcCurrency()
	{
		Currency r(2, 50);
		cout << r << endl;
		Currency c(3.5f);
		cin >> c;

		cout << r * 2 << endl;
		cout << &c - 2 << endl;
		cout << &c + (5.5f) << endl;
	}
}
