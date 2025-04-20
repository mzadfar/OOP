/**
 * @file test022.c
 * @author M. Z.
 * @brief Inserting a node at the beginning of a linked list
 * @version 0.1
 * @date 2025-02-18
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data; // char data;
  struct Node *next;
} Node;

// struct Node *head; /*Global variable, can be accessed anywhere*/

void insertNodeAtBegining(Node **head, int beginingNode);
void printList(Node *head);

int main() {
  struct Node *head = NULL; /*Empty list*/
  printf("How many node in the linked list? \n");
  int numOfNodes, beginingNode;
  scanf("%d", &numOfNodes);
  for (int i = 0; i < numOfNodes; i++) {
    printf("Enter a number as node \n");
    scanf("%d", &beginingNode);
    insertNodeAtBegining(&head, beginingNode);
    printList(head);
  }
  return 0;
}

void insertNodeAtBegining(
    Node **head, int beginingNode) { /*head is actually poiter to head*/
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = beginingNode;
  temp->next = *head;
  *head = temp;
  free(temp);
  temp = NULL;
}

void printList(Node *head) {
  printf("The list is: ");
  while (head != NULL) {
    printf(" %d", head->data);
    head = head->next;
  }
  printf("\n");
}