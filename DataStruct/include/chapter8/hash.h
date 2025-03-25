#pragma once
#include <string>
#include <algorithm>

using namespace std;

namespace Chapter8
{
	template <class T>
	class Hash
	{
	public:
		Hash(int _n);
		~Hash();

		size_t operator()(const string theKey) const
		{
			unsigned long hashValue = 0;
			int length = (int)theKey.length();
			for (int i = 0; i < length; ++i)
				hashValue = 5 * hashValue + theKey.at(i);
			return size_t(hashValue);
		}

		bool Insert(const T& key);
		bool Search(const T& key);
		bool Delete(const T& key);
		unsigned int StringToInt(string s);

	private:
		T* ht;
		int n;
	};
}

