/*Linked list: Deleting a node in the linked list*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data; // char data;
  Node *next;
};

Node *head; /*Global variable, can be accessed anywhere*/

void Insert(int data); /*At the end of the list*/
void Print();
void Delete(int position);

int main() {
  head = NULL; /*Empty list*/
  Insert(2);
  Insert(3);
  Insert(4);
  Insert(5);
  Print();
  int position;
  printf("Enter a position\n");
  scanf("%d", &position);
  Delete(position);
  Print();
}

void Insert(int data) {
  Node *temp1 = new Node();
  temp1->data = data; // Similar to (*temp).data = x;
  if (head == NULL) {
    temp1->next = head;
    head = temp1;
    return;
  }
  Node *temp2 = head;
  while (temp2->next != NULL) {
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

void Delete(int position) {
  Node *temp1 = head;
  if (position == 1) {
    head = temp1->next; /*head now points to second node*/
    delete temp1;
    return;
  }
  for (int i = 0; i < position - 2; i++) {
    temp1 = temp1->next;
  }
  /*temp1 points to (n-1)th node*/
  Node *temp2 = temp1->next; /*position node*/
  temp1->next = temp2->next; /*(position + 1) node*/
  delete temp2;
}
