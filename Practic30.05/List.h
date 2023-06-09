#pragma once
#include <iostream>
using namespace std;

class List
{
public:
	struct node {
		int id;
		string name;
		node* next;
	}* head, * tail, * ptr;

	List():head{nullptr}, tail{nullptr}, ptr{nullptr} {}
	~List();

	void displayList(node*); // ����������� � ������� ���� �����
	void displayNode(node*); // ����������� ����
	void addNode(node*); // ���������� ����
	void insertNode(node*); // ������� ����
	void deleteNode(node*); // �������� ����
	void deleteList(node*); // �������� ������

	node* initNode(string, int); // ������������� ���������
	node* searchName(node*, string); // ����� �� �����
	node* searchId(node*, int); //����� �� ID
};

