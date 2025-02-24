/**
 * @file test24.cpp
 * @author M. Z.
 * @brief Inserting a node at the beginning of a linked list
 * @version 0.1
 * @date 2025-02-20
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

  Node *insertNodeAtBeginning(Node *head, int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
  }

  void printList(Node *head) {
    cout << "The list is: ";
    while (head != nullptr) {
      cout << " " << head->data;
      head = head->next;
    }
    cout << endl;
  }
};

int main() {
  LinkedList myList;
  cout << ("How many node in the linked list? ") << endl;
  int numOfNodes, beginingNode;
  cin >> numOfNodes;
  for (int i = 0; i < numOfNodes; i++) {
    cout << "Enter a number as node: ";
    cin >> beginingNode;
    myList.head = myList.insertNodeAtBeginning(myList.head, beginingNode);
    myList.printList(myList.head);
  }
  return 0;
}