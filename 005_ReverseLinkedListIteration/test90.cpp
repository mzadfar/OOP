/*Linked list: Reversing a linked list through iteration*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data; // char data;
  Node *next;
};

// Node *head; /*Global variable, can be accessed anywhere*/

Node *Insert(Node *head, int data); /*At the end of the list*/
void Print(Node *head);
Node *Reverse(Node *head);

int main() {
  Node *head = NULL; /*Empty list*/
  head = Insert(head, 2);
  head = Insert(head, 3);
  head = Insert(head, 4);
  head = Insert(head, 5);
  Print(head);
  head = Reverse(head);
  Print(head);
}

Node *Insert(Node *head, int data) {
  Node *temp = new Node();
  temp->data = data; // Similar to (*temp).data = x;
  temp->next = head;
  head = temp;
  return head;
}

void Print(Node *head) {
  printf("List is: ");
  while (head != NULL) {
    printf(" %d ", head->data);
    head = head->next;
  }
  printf("\n");
}

Node *Reverse(Node *head) {
  Node *next, *prev, *current;
  current = head;
  prev = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
  return head;
}
