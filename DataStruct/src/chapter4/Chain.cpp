#include "chapter4/Chain.h"
#include <iostream>

using namespace std;

namespace Chapter4
{
	void ModifyChain()
	{
		Chain<int> chain;

		ChainNode<int>* node1 = new ChainNode<int>(10);
		ChainNode<int>* node2 = new ChainNode<int>(20);
		ChainNode<int>* node3 = new ChainNode<int>(30);

		chain.Insert(node1);
		chain.Insert(node2);
		chain.Insert(node3);

		cout << chain << endl;

		chain.Delete(node2);

		cout << chain << endl;
		cout << chain.Length() << endl;

		chain.Reverse();
		cout << chain << endl;
		cout << chain.Min() << endl;

		chain.Insert(40, 2);
		cout << chain << endl;
		cout << chain.Get(2) << endl;
	}
}

