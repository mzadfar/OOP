/**
 * @file test040.c
 * @author M. Z.
 * @brief Inserting a node at the end of a linked list
 * @version 0.1
 * @date 2025-03-03
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

Node *head;

void insertNodeAtEndOfList(int data);
void printList(void);

int main(void) {
  head = NULL;
  insertNodeAtEndOfList(9);
  insertNodeAtEndOfList(8);
  insertNodeAtEndOfList(7);
  insertNodeAtEndOfList(6);
  insertNodeAtEndOfList(5);
  insertNodeAtEndOfList(4);
  printList();
  return 0;
}

void insertNodeAtEndOfList(int data) {
  Node *temp1 = (Node *)malloc(sizeof(Node));
  temp1->data = data;
  temp1->next = NULL;
  if (head == NULL) {
    head = temp1;
  } else {
    Node *temp2 = (Node *)malloc(sizeof(Node));
    temp2 = head;
    while (temp2->next != NULL) {
      temp2 = temp2->next;
    }
    temp2->next = temp1;
  }
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