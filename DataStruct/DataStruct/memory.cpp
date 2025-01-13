#include "memory.h"

using namespace std;

namespace Chapter1 {

	Memory::Memory()
	{
	}

	Memory::~Memory()
	{
	}

	void NewandDelete()
	{
		Memory* m = new Memory();
		cout << "made class m" << endl;

		delete m;
		cout << "deleted class m" << endl;
	}
}
