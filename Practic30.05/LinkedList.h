#pragma once
#include <iostream>
using namespace std;

struct Node {
	int value;
	struct Node* next;
};

class LinkedList {
	Node* head;
	Node* tail;

public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	// добавление узла в конец списка
	void createNode(int val) {
		Node* temp = new Node;
		temp->value = val;
		temp->next = nullptr;

		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}
	// отображение узлов списка
	void printList() {
		Node* current = head;

		while (current != nullptr) {
			cout << current->value << endl;
			current = current->next;
		}
	}
	// вставка в начало списка
	void pushNode(int val) {
		Node* new_Node = new Node;

		new_Node->value = val;
		new_Node->next = head;

		head = new_Node;
	}
	// вставка узла в орпеделенную позицию
	void insertNodeAtPosition(int pos, int val) {
		Node* pre = nullptr; // предыдущий узел
		Node* current = nullptr; // следующий узел
		Node* temp = new Node; // новый узел
		
		current = head;

		for (int i = 1; i < pos; i++) {
			pre = current;
			current = current->next;
		}
		temp->value = val;
		pre->next = temp;
		temp->next = current;
	}
	// удаление первого элемента
	int pop() {
		int retVal = 0;
		Node* next_node = nullptr;

		next_node = head->next;
		retVal = head->value;
		delete head;
		head = next_node;

		return retVal;
	}
	// удаление последнего элемента
	int removeLast() {
		int retVal = 0;
		if (head->next == nullptr) {
			retVal = head->value;
			delete head;
			return retVal;
		}

		Node* current = head;
		while (current->next->next != nullptr)
		{
			current = current->next;
		}
		retVal = current->next->value;
		delete current->next;
		current->next = nullptr;

		return retVal;
	}
	// удаление определенного элемента
	int removeByIndex(int n) {
		int i = 0;
		int retVal = -1;
		Node* current = head;
		if (n == 0) return pop();

		for (i = 0; i < n - 1; i++) {
			if (current->next == nullptr) {
				return -1;
			}
			current = current->next;
		}

		Node* temp = current->next;
		retVal = temp->value;
		current->next = temp->next;
		delete temp;

		return retVal;
	}
};