/*Linked list: Reversing a linked list through recursion*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data; // char data;
  Node *next;
};

Node *head; /*Global variable, can be accessed anywhere*/

Node *Insert(Node *head, int data); /*At the end of the list*/
void Print(Node *head);
void ReversePrint(Node *head);
void Reverse(Node *node);

int main() {
  // Node *head = NULL; /*Empty list*/
  head = Insert(head, 2);
  head = Insert(head, 3);
  head = Insert(head, 4);
  head = Insert(head, 5);
  Print(head);
  printf("\n");
  Reverse(head);
  Print(head);
  printf("\n");
}

Node *Insert(Node *head, int data) {
  Node *temp = new Node();
  temp->data = data; // Similar to (*temp).data = x;
  temp->next = NULL;
  if (head == NULL) {
    head = temp;
  } else {
    Node *temp1 = head;
    while (temp1->next != NULL) {
      temp1 = temp1->next;
    }
    temp1->next = temp;
  }
  return head;
}

void Print(Node *node) {
  if (node == NULL) {
    return;
  }
  /*Like ReversePrint function below, if we revese 2 lines of codes below, it
   * will print the list reversely*/
  printf(" %d ", node->data);
  Print(node->next);
}

void ReversePrint(Node *node) {
  if (node == NULL) {
    return;
  }
  ReversePrint(node->next);
  printf(" %d ", node->data);
}

void Reverse(Node *node) {
  if (node->next == NULL) {
    head = node;
    return;
  }
  Reverse(node->next);
  // Node *temp = node->next;
  // temp->next = node;
  /*Below line can be replaaced instead of the above 2 lines*/
  node->next->next = node;
  node->next = NULL;
}
