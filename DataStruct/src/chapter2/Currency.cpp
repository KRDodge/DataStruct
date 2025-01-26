#include "chapter2/Rectangle.h"
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
		dollar = static_cast<int>(cur) / 100;
		cent = static_cast<int>(cur) % 100;
	}

	Currency::Currency() : dollar(0), cent(0)
	{

	}

	Currency::~Currency()
	{

	}

	Currency Currency::operator+(const float a)
	{
		float totalCents = dollar * 100 + cent + a * 100;
		return Currency(totalCents / 100, static_cast<int>(totalCents) % 100);
	}

	Currency Currency::operator-(const float a)
	{
		float totalCents = dollar * 100 + cent - a * 100;
		return Currency(totalCents / 100, static_cast<int>(totalCents) % 100);
	}

	Currency Currency::operator*(const float a)
	{
		float res = (dollar * 100 + cent) * a * 100;
		return Currency(res / 100, static_cast<int>(res) % 100);
	}

	void CalcCurrency()
	{
		Currency r(2, 50);
		cout << r << endl;
		Currency c(3.5f);
		cin >> c;

		cout << r * 2 << endl;
		cout << c - 2.5 << endl;
		cout << c + 5.5 << endl;
	}

	ostream& operator<<(ostream& os, const Currency& c)
	{
		os << "$" << c.dollar << ".";
		if (c.cent < 10)
			os << "0";
		os << c.cent;
		return os;
	}

	istream& operator>>(istream& is, Currency& c)
	{
		float a;
		is >> a;

		c.dollar = static_cast<int>(a);
		c.cent = static_cast<int>((a - c.dollar) * 100);
		return is;
	}
}
