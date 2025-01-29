#pragma once
#include <iostream>

using namespace std;

namespace Chapter2 {
	class Node 
    {
	public:
		int data;
		Node* next;

		Node(int value) {
			data = value;
			next = nullptr;
		}
	};

	class GeneralList
	{
    private:
        Node* head;

    public:
        GeneralList() {
            head = nullptr;
        }

        ~GeneralList() {
            Node* current = head;
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }

        void append(int value);
        void insert(int index, int value);

        void remove(int value) {
            if (!head) return;

            if (head->data == value) {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }

            Node* current = head;
            while (current->next && current->next->data != value) {
                current = current->next;
            }

            if (current->next) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }

        void display() {
            Node* current = head;
            while (current) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "NULL\n";
        }
	};

	void TestGeneralList();
}
