#pragma once

namespace Chapter7
{
	template <class E, class K>
	class Search
	{
	public:
		int SeqSearch(E* a, const int n, const K& k)
		{
			int i;
			for (i = 0; i < n && a[i] != k; i++);
			if (i > n)
				return -1;

			return i;
		}
	};
}