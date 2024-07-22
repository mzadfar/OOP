/*Linked list: Stack using linked list*/
#include <iostream>

using namespace std;

struct Node {
  int data; // char data;
  Node *next;
};

Node *top = NULL; /*Global variable, can be accessed anywhere*/

void Push(int data);
void Pop(void);
void Print();

int main() {
  top = NULL; /*Empty list*/
  Push(1);
  Print();
  Push(2);
  Print();
  Push(3);
  Print();
  Pop();
  Print();
  Push(4);
  Print();
}

void Push(int data) {
  Node *temp = new Node();
  temp->data = data; // Similar to (*temp).data = x;
  temp->next = top;
  top = temp;
}

void Pop(void) {
  Node *temp;
  if (top == NULL) {
    return;
  }
  temp = top;
  top = top->next;
  delete temp;
}

void Print() {
  Node *temp = top;
  printf("List is: ");
  while (temp != NULL) {
    printf(" %d ", temp->data);
    temp = temp->next;
  }
  printf("\n");
}