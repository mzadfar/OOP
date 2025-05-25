/**
 * @file test050.cpp
 * @author M. Z.
 * @brief Deleting a node in the linked list
 * @version 0.1
 * @date 2025-03-04
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

  void insertNodeInList(int data, int position) {
    Node *temp1 = new Node(data);
    temp1->data = data; // Similar to (*temp1).data = x;
    if (1 == position) {
      temp1->next = head;
      head = temp1;
    } else {
      Node *temp2 = head;
      for (int i = 0; i < position - 2; i++) {
        temp2 = temp2->next;
      }
      temp1->next = temp2->next;
      temp2->next = temp1;
    }
  }

  void deleteNodeInList(int position) {
    Node *temp1;
    temp1 = head;
    if (1 == position) {
      temp1 = temp1->next;
      head = temp1;
    } else {
      Node *temp2;
      for (int i = 0; i < position - 2; i++) {
        temp1 = temp1->next;
      }
      temp2 = temp1->next;
      temp1->next = temp2->next;
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
  LL.insertNodeInList(9, 1);
  LL.insertNodeInList(8, 2);
  LL.insertNodeInList(7, 3);
  LL.insertNodeInList(6, 4);
  LL.insertNodeInList(5, 5);
  LL.printList();
  int position;
  cout << "Enter a position to be deleted: ";
  cin >> position;
  LL.deleteNodeInList(position);
  LL.printList();
  return 0;
}
