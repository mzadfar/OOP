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

typedef struct Node {
  int data; // char data;
  Node *next;
} Node;

Node *head; /*Global variable, can be accessed anywhere*/

void insertNodeAtBegining(int beginingNode);
void printList();

int main() {
  head = nullptr; /*Empty list*/
  cout << ("How many node in the linked list? ") << endl;
  int numOfNodes, beginingNode;
  cin >> numOfNodes;
  for (int i = 0; i < numOfNodes; i++) {
    cout << "Enter a number as node " << endl;
    cin >> beginingNode;
    insertNodeAtBegining(beginingNode);
    printList();
  }
  return 0;
}

void insertNodeAtBegining(int beginingNode) {
  Node *temp = new Node;
  temp->data = beginingNode; 
  temp->next = head;
  head = temp;
  // delete temp;    // Deallocate memory when done
  // temp = nullptr; // Good practice to avoid dangling pointers
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