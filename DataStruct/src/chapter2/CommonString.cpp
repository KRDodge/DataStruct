#include "memory.h"
#include "chapter2/CommonString.h"
#include <algorithm>

using namespace std;

namespace Chapter2
{
	CommonString::CommonString()
	{
	}

	CommonString::CommonString(char* init, int m)
	{
		string = init;
		length = m;
	}

	CommonString::~CommonString()
	{
	}

	bool CommonString::operator==(CommonString t)
	{
		if (length != t.length)
			return false;
		for (int i = 0; i < length; ++i)
		{
			if (string[i] != t[i])
				return false;
		}
		return true;
	}

	bool CommonString::operator!()
	{
		return string != null && length > 0
	}

	int CommonString::Length()
	{
		return length;
	}

	CommonString CommonString::Concat(CommonString t)
	{
		length += t.length;
		string += t.string;
		return this;
	}

	CommonString CommonString::Substr(int i, int j)
	{
		return CommonString();
	}

	int CommonString::Find(CommonString pat)
	{
		for (int start = 0; start <= Length() - pat.Length(); start++)
		{
			int j;
			for (j = 0; j < pat.Length() && string[start + j] == pat.string[j]; j++)
			{
				if (j == pat.Length())
					return start;
			}
		}
		return -1;
	}

	int CommonString::FastFind(CommonString pat)
	{
		int posP = 0, posS = 0;
		int lengthP = pat.Length(), lengthS = Length();
		while (posP < lengthP && posS < lengthS)
		{
			if (pat.string[posP] == string[posS])
			{
				posP++; 
				posS++;
			}
			else
			{
				if (posP == 0)
					posS++;
				else
					posP = pat.f[posP - 1] + 1;
			}
			if (posP < lengthP)
				return -1;
			else return posS - lengthP;
		}
		return 0;
	}
}
