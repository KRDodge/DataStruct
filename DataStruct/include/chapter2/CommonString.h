#pragma once
#include <iostream>

using namespace std;

namespace Chapter2 
{
	class CommonString
	{
	public:
		CommonString();
		CommonString(char* init, int m);
		~CommonString();

		bool operator==(CommonString& t);
		bool operator!();

		int Length();

		CommonString& Concat(CommonString& t);
		CommonString Substr(int i, int j);
		
		friend istream& operator>>(istream& is, CommonString& t)
		{
			char* temp = new char[t.length + 1];
			for(int i = 0; i < t.length; ++i)
				is >> temp[i];
			t.string = temp;
			return is;
		}

		friend ostream& operator<<(ostream& os, CommonString& t)
		{
			for (int i = 0; i < t.length; ++i)
				os << t.string[i];
			os << endl;
			return os;
		}

		int Find(CommonString pat);
		void ComputeFailiureFunction(int* f, const char* pat);
		int FastFind(CommonString pat);

		void ReplaceSubstring(const char* w, const char* x);

		void CharDelete(char c);

	private:
		int length;
		char* string;
	};

	void StringInput();
}
