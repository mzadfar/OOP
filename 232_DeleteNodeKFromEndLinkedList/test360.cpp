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
Node *Delete(int positionFromEnd);

int main() {
  head = NULL; /*Empty list*/
  Insert(2);
  Insert(3);
  Insert(4);
  Insert(5);
  Print();
  int positionFromEnd;
  printf("Enter a position\n");
  scanf("%d", &positionFromEnd);
  head = Delete(positionFromEnd);
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

Node *Delete(int positionFromEnd) {
  Node *temp1 = head;
  Node *temp2 = head;
  int len = 0;

  while (positionFromEnd != 0) {
    temp2 = temp2->next;
    len++;
    positionFromEnd--;
  }

  if (temp2 == NULL) {
    if (len == 1) {
      head = NULL;
    } else {
      head =
          head->next; /*len is equal to length of list, so pass head to next*/
    }
    return head;
  }
  while (temp2->next != NULL) {
    temp1 = temp1->next;
    temp2 = temp2->next;
  }
  temp1->next = temp1->next->next;

  return head;
}
