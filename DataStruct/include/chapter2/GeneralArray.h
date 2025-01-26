#pragma once
#include <iostream>

using namespace std;

namespace Chapter2 {

	class GeneralArray
	{
	public:
		GeneralArray();
		GeneralArray(int size);
		GeneralArray(const GeneralArray& other);
		
		~GeneralArray();
        int GetSize() const;

        int& operator[](int index);

		GeneralArray& operator=(const GeneralArray& other);
        friend std::ostream& operator<<(std::ostream& os, const GeneralArray& arr);
        friend std::istream& operator>>(std::istream& is, GeneralArray& arr);
		
	private:
		int* data;
		int size;
	};

	void TestGeneralArray();
}
