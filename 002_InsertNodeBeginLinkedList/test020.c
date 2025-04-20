/**
 * @file test020.c
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

Node *head; /*Global variable, can be accessed anywhere*/

void insertNodeAtBegining(int beginingNode);
void printList();

int main() {
  head = NULL; /*Empty list*/
  printf("How many node in the linked list? \n");
  int numOfNodes, beginingNode;
  scanf("%d", &numOfNodes);
  for (int i = 0; i < numOfNodes; i++) {
    printf("Enter a number as node \n");
    scanf("%d", &beginingNode);
    insertNodeAtBegining(beginingNode);
    printList();
  }
  return 0;
}

void insertNodeAtBegining(int beginingNode) {
  Node *temp = (Node*) malloc(sizeof(Node));
  temp->data = beginingNode; // Similar to (*temp).data = x;
  /*temp->next = NULL;
  if (head != NULL) {
    temp->next = head;
  }*/
  /*below line covers commented above lines*/
  temp->next = head;
  head = temp;
  // free(temp);  // Deallocate memory when done
  // temp = NULL; // Good practice to avoid dangling pointers
}

void printList() {
  Node *temp = head;
  printf("The list is: ");
  while (temp != NULL) {
    printf(" %d", temp->data);
    temp = temp->next;
  }
  printf("\n");
}