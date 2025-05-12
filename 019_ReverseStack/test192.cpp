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

// Node *head = NULL; /*Global variable, can be accessed anywhere*/

Node *Add(char data);
Node *StringToLinkedList(string C, Node *head);
void Print(Node *head);
Node *Reverse(Node *head);

int main() {
  Node *head = NULL; /*Empty list*/
  printf("Enter a string: ");
  string C;
  cin >> C; // gets(C); doe not work
  head = StringToLinkedList(C, head);
  head = Reverse(head);
  Print(head);
  return 0;
}

// Function to add a new node to the Linked List
Node *Add(char data) {
  Node *newnode = new Node;
  newnode->data = data;
  newnode->next = NULL;
  return newnode;
}

// Function to convert the string to Linked List.
Node *StringToLinkedList(string C, Node *head) {
  head = Add(C[0]);
  Node *curr = head;

  // curr pointer points to the current node
  // where the insertion should take place
  for (int i = 1; i < C.size(); i++) {
    curr->next = Add(C[i]);
    curr = curr->next;
  }
  return head;
}

// Function to print the data present in all the nodes
void Print(Node *head) {
  Node *curr = head;
  while (curr != NULL) {
    cout << curr->data;
    curr = curr->next;
  }
  cout << "\n";
}

Node *Reverse(Node *head) {
  if (head == NULL) {
    return head;
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
  return head;
}
