/**
 * @file test022.cpp
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

struct Node {
  int data;
  Node *next;
};

void insertNodeAtBegining(Node **head, int beginingNode);
void printList(Node *head);

int main() {
  Node *head = nullptr; /*Empty list*/
  cout << ("How many node in the linked list? ") << endl;
  int numOfNodes, beginingNode;
  cin >> numOfNodes;
  for (int i = 0; i < numOfNodes; i++) {
    cout << "Enter a number as node " << endl;
    cin >> beginingNode;
    insertNodeAtBegining(&head, beginingNode);
    printList(head);
  }
  return 0;
}

void insertNodeAtBegining(Node **head, int beginingNode) {
  Node *temp = new Node;
  temp->data = beginingNode; 
  temp->next = *head;
  *head = temp;
  // delete temp;    // Deallocate memory when done
  // temp = nullptr; // Good practice to avoid dangling pointers
}

void printList(Node *head) {
  cout << "The list is: ";
  while (head != nullptr) {
    cout << " " << head->data;
    head = head->next;
  }
  cout << endl;
}
