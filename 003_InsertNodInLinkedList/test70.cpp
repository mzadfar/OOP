/*Linked list: Inserting a node in the linked list*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data; // char data;
  Node *next;
};

Node *head; /*Global variable, can be accessed anywhere*/

void Insert(int data, int position);
void Print();

int main() {
  head = NULL; /*Empty list*/
  Insert(2, 1);
  Insert(3, 2);
  Insert(4, 1);
  Insert(5, 2);
  Print();
}

void Insert(int data, int position) {
  Node *temp1 = new Node();
  temp1->data = data; // Similar to (*temp).data = x;
  if (position == 1) {
    temp1->next = head;
    head = temp1;
    return;
  }
  Node *temp2 = head;
  for (int i = 0; i < position - 2; i++) {
    temp2 = temp2->next;
  }
  temp1->next = temp2->next;
  temp2->next = temp1;
}

void Print() {
  Node *temp = head;
  printf("List is: ");
  while (temp != NULL) {
    printf(" %d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}