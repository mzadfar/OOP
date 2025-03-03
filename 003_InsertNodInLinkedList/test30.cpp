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
#include <iostream>

using namespace std;

struct Node {
  int data; // char data;
  Node *next;
};

Node *head; /*Global variable, can be accessed anywhere*/

void insertNodeInList(int data, int position);
void printList();

int main() {
  head = NULL; /*Empty list*/
  insertNodeInList(2, 1);
  insertNodeInList(3, 2);
  insertNodeInList(4, 1);
  insertNodeInList(5, 2);
  printList();
}

void insertNodeInList(int data, int position) {
  Node *temp1 = new Node();
  temp1->data = data; // Similar to (*temp).data = x;
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