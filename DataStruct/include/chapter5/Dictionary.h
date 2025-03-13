#pragma once
#include "stl.h"

using namespace std;

namespace Chapter5
{
	template <class K, class E> 
	class Dictionary
	{
	public:
		virtual bool IsEmpty() const = false;
		virtual pair<K, E>* Get(const K&) const = 0;
		virtual void Insert(const pair<K, E>&) = 0;
		virtual void Delete(const K&) = 0;
	}
}