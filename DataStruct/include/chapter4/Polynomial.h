#pragma once
#include "chapter4/Chain.h"
#include <iostream>

using namespace std;

namespace Chapter4 {
	struct Term
	{
		int coef;
		int exp;
		Term Set(int c, int e)
		{
			coef = c;
			exp = e;
			return *this;
		}
	};

	class Polynomial {
	public:
		Polynomial();
		~Polynomial();

		Polynomial operator+(const Polynomial& b) {
			Term temp;
			Chain<Term>::ChainIterator  ai = poly->begin();
			Chain<Term>::ChainIterator  bi = b.poly->begin();

			Polynomial c;

			while (ai && bi)
			{
				if (ai->exp == bi->exp)
				{
					int sum = ai->coef + bi->coef;
					if (sum)
					{
						c.poly->InsertBack(temp.Set(sum, ai->exp));
						ai++;
						bi++;
					}
				}
				else if (ai->exp < bi->exp)
				{
					c.poly->InsertBack(temp.Set(bi->coef, bi->exp));
					bi++;
				}
				else
				{
					c.poly->InsertBack(temp.Set(ai->coef, ai->exp));
					ai++;
				}
			}

			while (ai)
			{
				c.poly->InsertBack(temp.Set(ai->coef, ai->exp));
				ai++;
			}

			while (bi)
			{
				c.poly->InsertBack(temp.Set(bi->coef, bi->exp));
				bi++;
			}
			return c;
		}

		Polynomial operator-(const Polynomial& b) 
		{
			return Polynomial();
		}

		int Evaluate(int e);

		friend istream& operator>>(istream& is, Polynomial& p)
		{
			int n;
			is >> n;
			int e, c;
			Term temp;
			for (int i = 0; i < n; ++i)
			{
				is >> e >> c;
				temp.Set(c, e);
				p.poly->InsertBack(temp);
			}
			return is;
		}

	private:
		Chain<Term>* poly;
	};

	void ChainPolyTest();
}

