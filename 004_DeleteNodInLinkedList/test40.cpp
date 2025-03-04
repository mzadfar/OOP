/**
 * @file test40.cpp
 * @author M. Z.
 * @brief Deleting a node in the linked list
 * @version 0.1
 * @date 2025-03-03
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <iostream>

using namespace std;

struct Node {
  int data; // char data;
  Node *next;
};

Node *head; /*Global variable, can be accessed anywhere*/

void insertNodeInList(int data, int position); /*At the end of the list*/
void printList();
void deleteNodeInList(int position);

int main() {
  head = NULL; /*Empty list*/
  insertNodeInList(9, 1);
  insertNodeInList(8, 2);
  insertNodeInList(7, 3);
  insertNodeInList(6, 4);
  insertNodeInList(5, 5);
  printList();
  int position;
  cout << "Enter a position to be deleted: ";
  cin >> position;
  deleteNodeInList(position);
  printList();
}

void insertNodeInList(int data, int position) {
  Node *temp1 = new Node();
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

void printList() {
  Node *temp = head;
  cout << "List is: ";
  while (temp != NULL) {
    cout << " " << temp->data;
    temp = temp->next;
  }
  cout << endl;
}

void deleteNodeInList(int position) {
  Node *temp1 = head;
  if (position == 1) {
    head = temp1->next; /*head now points to second node*/
    delete temp1;
    return;
  }
  for (int i = 0; i < position - 2; i++) {
    temp1 = temp1->next;
  }
  /*temp1 points to (position-1)th node*/
  Node *temp2 = temp1->next; /*temp2 at position node*/
  temp1->next = temp2->next; /*(position + 1) node*/
  delete temp2;
}
