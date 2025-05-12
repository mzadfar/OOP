/*Linked list: Reverse stack using linked list*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

struct Node {
  char data;
  Node *next;
};

Node *head = NULL; /*Global variable, can be accessed anywhere*/

Node *Add(char data);
void StringToLinkedList(string C);
void Print(void);
void Reverse(void);

int main() {
  printf("Enter a string: ");
  string C;
  cin >> C; // gets(C); doe not work
  StringToLinkedList(C);
  Reverse();
  Print();
  return 0;
}

// Function to add a new node to the Linked List
Node *Add(char data) {
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

// Function to convert the string to Linked List.
void StringToLinkedList(string C) {
  head = Add(C[0]);
  Node *curr = head;

  // curr pointer points to the current node
  // where the insertion should take place
  for (int i = 1; i < C.size(); i++) {
    curr->next = Add(C[i]);
    curr = curr->next;
  }
}

// Function to print the data present in all the nodes
void Print(void) {
  Node *curr = head;
  while (curr != NULL) {
    cout << curr->data;
    curr = curr->next;
  }
  cout << "\n";
}

void Reverse(void) {
  if (head == NULL) {
    return;
  }
  stack<Node *> S;
  Node *temp = head;
  while (temp != NULL) {
    S.push(temp);
    temp = temp->next;
  }
  temp = S.top();
  head = temp;
  S.pop();
  while (!S.empty()) {
    temp->next = S.top();
    S.pop();
    temp = temp->next;
  }
  temp->next = NULL;
}
