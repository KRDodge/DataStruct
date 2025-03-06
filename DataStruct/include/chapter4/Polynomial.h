#pragma once
#include "chapter4/Chain.h"
#include <iostream>
#include <map>

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

		Polynomial operator+(const Polynomial& b) 
		{
			Term temp;
			Chain<Term>::ChainIterator  ai = poly->begin();
			Chain<Term>::ChainIterator  bi = b.poly->begin();

			Polynomial c;

			while (ai && bi)
			{
				if (ai->exp == bi->exp)
				{
					int sum = ai->coef + bi->coef;
					if (sum != 0)
						c.poly->InsertBack(temp.Set(sum, ai->exp));
					ai++;
					bi++;
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
			Term temp;
			Chain<Term>::ChainIterator  ai = poly->begin();
			Chain<Term>::ChainIterator  bi = b.poly->begin();

			Polynomial c;

			while (ai && bi)
			{
				if (ai->exp == bi->exp)
				{
					int subt = ai->coef - bi->coef;
					if (subt != 0)
						c.poly->InsertBack(temp.Set(subt, ai->exp));
					ai++;
					bi++;
				}
				else if (ai->exp < bi->exp)
				{
					c.poly->InsertBack(temp.Set(-(bi->coef), bi->exp));
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

		Polynomial operator*(const Polynomial& b) 
		{
			Term temp;
			Chain<Term>::ChainIterator ai = poly->begin();
			Chain<Term>::ChainIterator bi;
			map<int, int> terms;

			Polynomial c;

			while (ai)
			{
				bi = b.poly->begin();
				while (bi)
				{
					int coefMult = ai->coef * bi->coef;
					int expMult = ai->coef + bi->coef;
					terms[expMult] += coefMult;
					bi++;
				}	
				ai++;
			}

			for (const auto& term : terms)
			{
				if (term.second != 0)
					c.poly->InsertBack(Term(term.second, term.first));
			}

			return c;
		}

		int Evaluate(int e)
		{
			int sum = 0;
			Chain<Term>::ChainIterator it;
			for (auto it = poly->begin(); it != poly->end(); it++)
			{
				sum += pow(e, it->exp) * it->coef;
			}

			return sum;
		}

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

