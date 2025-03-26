#include "chapter8/hash.h"

namespace Chapter8
{
	template<class T>
	Hash<T>::Hash(int _n)
	{
		n = _n;
		ht = new int[n];
	}

	template<class T>
	Hash<T>::~Hash()
	{
		delete[] ht;
	}

	template<class T>
	bool Hash<T>::Insert(const T& key)
	{
		unsigned int index = StringToInt(key) % n;
		int originalIndex = index;
		int count = 0;
		T empty = T();

		while (count < n)
		{
			if (ht[index] == empty)
			{
				ht[index] = key;
				return true;
			}
			index = (index + 1) % n;
			count++;
		}
		return false;
	}

	template<class T>
	bool Hash<T>::Search(const T& key)
	{
		unsigned int index = StringToInt(key) % n;
		int count = 0;
		T empty = T();

		while (count < n)
		{
			if (ht[index] == key)
				return true;
			if (ht[index] == empty)
				return false;
			index = (index + 1) % n;
			count++;
		}
		return false;
	}

	template<class T>
	bool Hash<T>::Delete(const T& key)
	{
		unsigned int index = StringToInt(key) % n;
		int count = 0;
		T empty = T();

		while (count < n)
		{
			if (ht[index] == key)
			{
				ht[index] = empty;
				return true;
			}
			if (ht[index] == empty)
				return false;
			index = (index + 1) % n;
			count++;
		}
		return false;
	}

	template <class T>
	unsigned int Hash<T>::StringToInt(string s)
	{
		int length = (int)s.length();
		unsigned int answer = 0;
		if (length % 2 == 1)
		{
			answer = s.at(length - 1);
			length--;
		}
		for (int i = 0; i < length; i += 2)
		{
			answer += s.at(i);
			answer += ((int)s.at(i + 1)) << 8;
		}
		return answer;
	}

}
