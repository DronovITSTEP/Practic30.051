#include <iostream>
#include "List.h"

using namespace std;

//--------------------- двусвязный список -------------------//
struct Node {
    int data;

    Node* next;
    Node* prev;
};
// вставка узла в начало двусвязного списка
void insertFront(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    newNode->next = (*head);
    newNode->prev = nullptr;

    if ((*head) != nullptr) (*head)->prev = newNode;
    (*head) = newNode;
}
// вставка узла в определенную позицию списка
void insertAfter(Node* prev_node, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;

    if (newNode->next != nullptr)
        newNode->next->prev = newNode;
}
// вставка узла в конец списка
void insertEnd(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;

    newNode->next = nullptr;

    Node* temp = *head;
    // если в списке нет узлов
    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }

    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

}
// удаление узла из списка
void deleteNode(Node** head, Node* del_node) {
    if (*head == nullptr || del_node == nullptr)
        return;

    if (*head == del_node)
        *head = del_node->next;

    if (del_node->prev != nullptr)
        del_node->prev->next = del_node->next;
    if (del_node->next != nullptr)
        del_node->next->prev = del_node->prev;

    //delete del_node;
    free(del_node);
}
// вывод списка в консоль
void displayList(Node* node) {
    Node* last;

    while (node != nullptr) {
        cout << node->data << "... ";
        last = node;
        node = node->next;
    }

    if (node == nullptr)
        cout << "NULL\n";
}
//--------------------- двусвязный список -------------------//

int main()
{
    /*int id;
    string name;
    List myList;
    List::node* ptr;
    // добавление
    ptr = myList.initNode("string 1", 1);
    myList.addNode(ptr);
    ptr = myList.initNode("string 6", 6);
    myList.addNode(ptr);
    ptr = myList.initNode("string 4", 4);
    myList.addNode(ptr);
    ptr = myList.initNode("string 2", 2);
    myList.addNode(ptr);

    myList.displayList(myList.head);
    cout << endl;

    ptr = myList.initNode("string 3", 3);
    myList.insertNode(ptr);
    myList.displayList(myList.head);
    cout << endl;

    name = "string 4";
    ptr = myList.searchName(myList.head, name);
    if (ptr == nullptr) cout << "\nName: " << name << " not found" << endl;
    else {
        myList.deleteNode(ptr);
    }
    myList.displayList(myList.head);

    cout << endl;
    myList.deleteList(myList.head);
    myList.displayList(myList.head);*/

    /*
    Node* head = nullptr;

    insertEnd(&head, 5);
    insertFront(&head, 1);
    insertFront(&head, 8);
    insertEnd(&head, 7);
    displayList(head);
    cout << endl;

    insertAfter(head, 11);
    insertAfter(head->next->next, 26);
    displayList(head);
    cout << endl;

    deleteNode(&head, head->next->next->next);
    displayList(head);
    cout << endl;
    */

}