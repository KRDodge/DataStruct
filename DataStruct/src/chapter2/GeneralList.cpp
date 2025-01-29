#include "chapter2/GeneralList.h"
#include "memory.h"

namespace Chapter2
{
	void GeneralList::append(int value)
	{
		Node* newNode = new Node(value);
		if (!head) {
			head = newNode;
			return;
		}
		Node* current = head;
		while (current->next) {
			current = current->next;
		}
		current->next = newNode;
	}

	void GeneralList::insert(int index, int value) 
	{
		Node* newNode = new Node(value);
		if (index == 0) {
			newNode->next = head;
			head = newNode;
			return;
		}

		Node* current = head;
		for (int i = 0; i < index - 1 && current; i++) {
			current = current->next;
		}

		if (!current) {
			std::cout << "Invalid index!\n";
			return;
		}

		newNode->next = current->next;
		current->next = newNode;
	}

	void TestGeneralList()
	{
		GeneralList list;
	}
}
