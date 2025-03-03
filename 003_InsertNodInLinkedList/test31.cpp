/**
 * @file test30.cpp
 * @author M. Z.
 * @brief Inserting a node in the linked list
 * @version 0.1
 * @date 2025-03-03
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <cstddef>
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

  void insertNodeInList(int data, int position) {
    Node *temp1 = new Node(data);
    if (position == 1) {
      temp1->next = head;
      head = temp1;
      return;
    }
    Node *temp2 = head;
    for (int i = 0; i < position - 2;
         i++) { // i = 0 (position = 3) means the second swap after head
      temp2 = temp2->next;
    }
    temp1->next = temp2->next; // for position =2 temp1->next = head->next
    temp2->next = temp1;       // for position =2 head->next = temp1
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
  LL.insertNodeInList(2, 1);
  LL.insertNodeInList(3, 2);
  LL.insertNodeInList(4, 1);
  LL.insertNodeInList(5, 2);
  LL.printList();
}
