#include "chapter2/GeneralArray.h"
#include "memory.h"

namespace Chapter2
{
	GeneralArray::GeneralArray()
	{
	}

	GeneralArray::GeneralArray(int size)
	{
		if (size <= 0) {
			throw std::invalid_argument("Size must be positive.");
		}
		data = new int[size]();
	}

	GeneralArray::GeneralArray(const GeneralArray& other) : size(other.size)
	{
		data = new int[size];
		for (int i = 0; i < size; ++i)
			data[i] = other.data[i];
	}

	GeneralArray::~GeneralArray()
	{
		delete[] data;
	}

	int GeneralArray::GetSize() const
	{
		return size;
	}

	int& GeneralArray::operator[](int index)
	{
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range.");
		}
		return data[index];
	}

	GeneralArray& GeneralArray::operator=(const GeneralArray& other)
	{
		if (this != &other) {
			delete[] data;

			size = other.size;
			data = new int[size];
			for (int i = 0; i < size; ++i) {
				data[i] = other.data[i];
			}
		}
		return *this;
	}

	ostream& operator<<(ostream& os, const GeneralArray& arr)
	{
		for (int i = 0; i < arr.size; ++i)
			os << arr.data[i];
		return os;
	}
	
	istream& operator>>(istream& is, GeneralArray& arr) {
		is >> arr.size;
		arr.data = new int[arr.size]();
		for (int i = 0; i < arr.size; ++i) {
			is >> arr.data[i];
		}
		return is;
	}

	void TestGeneralArray()
	{
		GeneralArray arr;
		cin >> arr;

		GeneralArray copied(arr);
		GeneralArray equalCopied = arr;
		cout << arr << endl;
		cout << copied[0] << endl;
		cout << equalCopied.GetSize() << endl;
	}
}
