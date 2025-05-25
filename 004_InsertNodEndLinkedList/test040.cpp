/**
 * @file test040.cpp
 * @author M. Z.
 * @brief Inserting a node at the end of a linked list
 * @version 0.1
 * @date 2025-03-03
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *next;

  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

class LinkedList {
public:
  Node *head;
  
  LinkedList() { this->head = nullptr; }

  void insertNodeAtEndOfList(int data) {
    Node *temp1 = new Node(data);
    temp1->data = data;
    temp1->next= nullptr;
    if (head == nullptr) {
      head = temp1;
    }else{
    Node *temp2 = head;
    while (temp2->next != nullptr) { // (position = 3) means the first swap
      temp2 = temp2->next;
    }
    temp2->next = temp1;      
  }
  }

  void printList() {
    Node *temp = head;
    cout << "List is: ";
    while (temp != NULL) {
      cout << " " << temp->data;
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList LL;
  LL.insertNodeAtEndOfList(2);
  LL.insertNodeAtEndOfList(3);
  LL.insertNodeAtEndOfList(4);
  LL.insertNodeAtEndOfList(5);
  LL.printList();
}
