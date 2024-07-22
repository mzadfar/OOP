/*Linked list: Insert node at the begining of a doubly linked list*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data; // char data;
  Node *next;
  Node *prev;
};

Node *head; /*Global variable, can be accessed anywhere*/

Node *GetNewNode(int data);
void InsertAtHead(int data); /*At the head of the list*/
void InsertAtTail(int data); /*At the tail of the list*/
void Print(void);
void ReversePrint(void);

int main() {
  head = NULL; /*Empty list*/
  InsertAtHead(2);
  Print();
  ReversePrint();
  InsertAtHead(3);
  Print();
  ReversePrint();
  InsertAtTail(4);
  Print();
  ReversePrint();
  InsertAtTail(5);
  Print();
  ReversePrint();
}

Node *GetNewNode(int data) {
  Node *newNode = new Node();
  newNode->data = data; // Similar to (*temp).data = x;
  newNode->next = NULL;
  newNode->prev = NULL;
  return newNode;
}

void InsertAtHead(int data) {
  Node *newNode = GetNewNode(data);
  if (head == NULL) {
    head = newNode;
    return;
  }
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}

void InsertAtTail(int data) {
  Node *temp = head;
  Node *newNode = GetNewNode(data);
  if (head == NULL) {
    head = newNode;
    return;
  }
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
  newNode->prev = temp;
}

void Print(void) {
  Node *temp = head;
  printf("Forward: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void ReversePrint(void) {
  Node *temp = head;
  if (temp == NULL) {
    return;
  }
  while (temp->next != NULL) {
    temp = temp->next;
  }
  printf("Rverse: ");
  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->prev;
  }
  printf("\n");
}
