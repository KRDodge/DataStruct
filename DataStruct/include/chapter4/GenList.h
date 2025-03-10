#pragma once

namespace Chapter4
{
	template <class T> class GenList;

	template<class T>
	class GenListNode
	{
		friend class GenList<T>;
	private:
		GenListNode<T>* next;
		int tag;
		union
		{
			T data;
			GenListNode<T>* down;
			int ref;
		};
	};

	template <class T>
	class GenList
	{
	public:
		GenList();
		~GenList();

		void Copy(const GenList<T>& l) const;
		GenListNode<T>* Copy(GenListNode<T>* p);
		void Delete(GenListNode<T>* x);
		void Insert(GenListNode<T>* x);

		bool operator==(const GenList<T>& l) const;
		bool Equal(GenListNode<T>* s, GenListNode<T>* t);
		int Depth();
		int Depth(GenListNode<T>* s);

	private:
		GenListNode<T>* first;
		GenListNode<T>* av;
	};
}