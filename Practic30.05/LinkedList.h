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
	// ���������� ���� � ����� ������
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
	// ����������� ����� ������
	void printList() {
		Node* current = head;

		while (current != nullptr) {
			cout << current->value << endl;
			current = current->next;
		}
	}
	// ������� � ������ ������
	void pushNode(int val) {
		Node* new_Node = new Node;

		new_Node->value = val;
		new_Node->next = head;

		head = new_Node;
	}
	// ������� ���� � ������������ �������
	void insertNodeAtPosition(int pos, int val) {
		Node* pre = nullptr; // ���������� ����
		Node* current = nullptr; // ��������� ����
		Node* temp = new Node; // ����� ����
		
		current = head;

		for (int i = 1; i < pos; i++) {
			pre = current;
			current = current->next;
		}
		temp->value = val;
		pre->next = temp;
		temp->next = current;
	}
	// �������� ������� ��������
	int pop() {
		int retVal = 0;
		Node* next_node = nullptr;

		next_node = head->next;
		retVal = head->value;
		delete head;
		head = next_node;

		return retVal;
	}
	// �������� ���������� ��������
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
	// �������� ������������� ��������
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