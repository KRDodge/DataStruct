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

	bool CommonString::operator==(CommonString &t)
	{
		if (length != t.length)
			return false;
		for (int i = 0; i < length; ++i)
		{
			if (string[i] != t.string[i])
				return false;
		}
		return true;
	}

	bool CommonString::operator!()
	{
		return string != nullptr && length > 0;
	}

	int CommonString::Length()
	{
		return length;
	}

	CommonString& CommonString::Concat(CommonString &t)
	{
		int newLength = length + t.length;
		char* newString = new char[newLength + 1];

		strncpy(newString, string, length);
		strncpy(newString + length, t.string, t.length);

		newString[newLength] = '\0';

		delete[] string;
		string = newString;
		length = newLength;

		return *this;
	}

	CommonString CommonString::Substr(int i, int j)
	{
		int newLength = j - i + 1;
		char* newString = new char[newLength + 1];

		for (int k = 0; k < newLength; ++k)
			newString[k] = string[i + k];


		newString[newLength] = '\0';
		return CommonString(newString, newLength);
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

	void CommonString::ComputeFailiureFunction(int* f, const char* pat)
	{
		int lengthP = Length();
		f[0] = -1;
		for (int j = 1; j < lengthP; ++j)
		{
			int i = f[j - 1];
			while ((*(string + j) != *(string + i + 1)) && (i >= 0))
				i = f[i];
			if (*(string + j) == *(string + i + 1))
				f[j] = i + 1;
			else
				f[j] = -1;
		}
	}

	int CommonString::FastFind(CommonString pat)
	{
		int posP = 0, posS = 0;
		int lengthP = pat.Length(), lengthS = Length();

		int* f = new int[lengthP];
		pat.ComputeFailiureFunction(f, pat.string);

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
					posP = f[posP - 1] + 1;
			}
			if (posP < lengthP)
				return -1;
			else 
				return posS - lengthP;
		}
		return 0;
	}

	void CommonString::ReplaceSubstring(const char* w, const char* x) {
		int wLen = strlen(w);
		int xLen = strlen(x);

		for (int i = 0; i <= length - wLen; ) 
		{
			if (strncmp(&string[i], w, wLen) == 0)
			{
				if (wLen == xLen)
				{
					strncpy(&string[i], x, xLen);
				}
				else if (wLen > xLen)
				{
					strncpy(&string[i], x, xLen);
					memmove(&string[i + xLen], &string[i + wLen], length - (i + wLen) + 1);
				}
				else
				{
					memmove(&string[i + xLen], &string[i + wLen], length - (i + wLen) + 1);
					strncpy(&string[i], x, xLen);
				}
				length += (xLen - wLen);
				i += xLen;
			}
			else
				i++;
		}
	}

	void CommonString::CharDelete(char c)
	{
		int newLength = 0;
		for (int i = 0; i < length; ++i)
		{
			if (string[i] != c)
				string[newLength++] = string[i];
		}
		length = newLength;
		string[newLength] = '\0';
	}

	void StringInput()
	{
		int length = 0;
		cout << "input length" << endl;
		cin >> length;
		CommonString s1(nullptr, length);
		cin >> s1;
		cout << s1 << endl;
		CommonString s2(nullptr, length);
		cin >> s2;
		cout << s2 << endl;

		cout << (s1 == s2) << endl;
		CommonString s3 = s1.Concat(s2);
		cout << s3 << endl;
		CommonString s4 = s3.Substr(2, 4);
		cout << s4 << endl;
	}
}
