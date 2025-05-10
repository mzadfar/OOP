#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Data structure to store a XOR linked list node
struct Node {
  int data;
  struct Node *link;
};

// Helper function to return XOR of `x` and `y`
struct Node *XOR(struct Node *x, struct Node *y) {
  return (struct Node *)((uintptr_t)(x) ^ (uintptr_t)(y));
}

// Helper function to traverse the list in a forward direction
void traverse(struct Node *head) {
  struct Node *curr = head;
  struct Node *prev = NULL;
  struct Node *next;

  while (curr != NULL) {
    printf("%d —> ", curr->data);

    // `next` node would be xor of the address of the previous node
    // and current node link
    next = XOR(prev, curr->link);

    // update `prev` and `curr` pointers for the next iteration of the loop
    prev = curr;
    curr = next;
  }

  printf("NULL");
}

// Helper function to insert a node at the beginning of the XOR linked list
void push(struct Node **head, int data) {
  // allocate a new list node and set its data
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;

  // The link field of the new node is XOR of the current head and `NULL`
  // since a new node is being inserted at the beginning
  newNode->link = XOR(*head, NULL);

  // update link value of the current head node if the linked list is not empty
  if (*head) {
    // *(head)->link is XOR of `NULL` and address of the next node.
    // To get the address of the next node, XOR it with `NULL`
    (*head)->link = XOR(newNode, XOR((*head)->link, NULL));
  }

  // update the head pointer
  *head = newNode;
}

int main(void) {
  // input keys
  int keys[] = {1, 2, 3, 4, 5};
  int n = sizeof(keys) / sizeof(keys[0]);

  struct Node *head = NULL;
  for (int i = n - 1; i >= 0; i--) {
    push(&head, keys[i]);
  }

  traverse(head);

  return 0;
}