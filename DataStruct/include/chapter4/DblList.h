#pragma once

namespace Chapter4
{
	class DblList;

	class DblListNode
	{
		friend class DblList;
	private:
		int data;
		DblListNode* left;
		DblListNode* right;
	};

	class DblList 
	{
	public:
		void Delete(DblListNode* x);
		void Insert(DblListNode* p, DblListNode* x);
		
		void InsertFront(DblListNode* p);
		void InsertBack(DblListNode* p);

		void Concatenate(DblList* p);

	private:
		DblListNode* first;
		DblListNode* last;
	};
}
