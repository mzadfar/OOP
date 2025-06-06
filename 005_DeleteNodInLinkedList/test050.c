/**
 * @file test050.c
 * @author M. Z.
 * @brief Deleting a node in the linked list
 * @version 0.1
 * @date 2025-03-03
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <memory.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *head;

void insertNodeInList(int data, int position);
void printList(void);
void deleteNodeInList(int position);

int main(void) {
  head = NULL; /*Empty list*/
  insertNodeInList(9, 1);
  insertNodeInList(8, 2);
  insertNodeInList(7, 3);
  insertNodeInList(6, 4);
  insertNodeInList(5, 5);
  insertNodeInList(4, 6);
  printList();
  int position;
  printf("Enter a position: \n");
  scanf("%d", &position);
  deleteNodeInList(position);
  printList();
  return 0;
}

void insertNodeInList(int data, int position) {
  Node *temp1 = (Node *)malloc(sizeof(Node));
  temp1->data = data;
  if (1 == position) {
    temp1->next = head;
    head = temp1;
    return;
  }
  Node *temp2 = (Node *)malloc(sizeof(Node));
  temp2 = head;
  for (int i = 0; i < (position - 2);
       i++) { // i = 0 (position = 3) means the second swap after head
    temp2 = temp2->next;
  }
  temp1->next = temp2->next; // for position =2 temp1->next = head->next
  temp2->next = temp1;       // for position =2 head->next = temp1
}

void printList(void) {
  Node *temp = head;
  printf("The list is: ");
  while (temp != NULL) {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}

void deleteNodeInList(int position) {
  Node *temp1 = head;
  if (1 == position) {
    temp1 = temp1->next;
    head = temp1;
    return;
  } else {
    for (int i = 0; i < position - 2;
         i++) { // (position = 3) means the first swap
      temp1 = temp1->next;
    }
    /*temp1 points to (position-1)th node*/
    Node *temp2 = temp1->next; /*temp2 at position node*/
    temp1->next = temp2->next; /*(position + 1) node*/
  }
}