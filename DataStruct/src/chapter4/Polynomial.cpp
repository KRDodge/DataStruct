#include "chapter4/Polynomial.h"
#include "chapter4/Chain.h"
#include "chapter4/ChainIterator.h"
#include <math.h>

namespace Chapter4
{
	Polynomial::Polynomial()
	{
		poly = new Chain<Term>();
	}

	Polynomial::~Polynomial()
	{
	}

	void ChainPolyTest()
	{
		Polynomial p1, p2;
		cin >> p1;
		cout << "p1 ended" << endl;
		cin >> p2;
		cout << "p2 ended" << endl;
		
		Polynomial p3 = p1 + p2;

		cout << p3.Evaluate(2) << endl;

		p3 = p1 - p2;
		cout << p3.Evaluate(2) << endl;

		p3 = p1 * p2;
		cout << p3.Evaluate(2) << endl;
	}
}

