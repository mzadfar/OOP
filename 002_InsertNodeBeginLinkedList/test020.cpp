/**
 * @file test020.cpp
 * @author M. Z.
 * @brief Inserting a node at the beginning of a linked list
 * @version 0.1
 * @date 2025-02-19
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

  void insertNodeAtBegining(int data) {
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
  }

  void printList() {
    Node *temp = head;
    cout << "The list is: ";
    while (temp != nullptr) {
      cout << " " << temp->data;
      temp = temp->next;
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
    myList.insertNodeAtBegining(beginingNode);
    myList.printList();
  }
  return 0;
}