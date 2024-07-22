/*Linked list: Inserting a node at the beginning of the linked list*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data; // char data;
  struct Node *next;
};

// struct Node *head; /*Global variable, can be accessed anywhere*/

struct Node *Insert(struct Node *head, int x);
void Print(struct Node *head);

int main() {
  struct Node *head = NULL; /*Empty list*/
  printf("How many numbers?\n");
  int n, i, x;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    printf("Enter the number \n");
    scanf("%d", &x);
    head = Insert(head, x);
    Print(head);
  }
}

struct Node *Insert(struct Node *head, int x) {
  struct Node *temp = malloc(sizeof(struct Node));
  temp->data = x; // Similar to (*temp).data = x;
  /*temp->next = NULL;
  if (head != NULL) {
    temp->next = head;
  }*/
  /*below line covers commented above lines*/
  temp->next = head;
  head = temp;
  return head;
}

void Print(struct Node *head) {
  printf("List is: ");
  while (head != NULL) {
    printf(" %d", head->data);
    head = head->next;
  }
  printf("\n");
}