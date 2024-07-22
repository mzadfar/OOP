/*Linked list: Reverse stack using array*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>

using namespace std;

struct Node {
  int data; // char data;
  Node *next;
};

Node *top = NULL; /*Global variable, can be accessed anywhere*/

void Reverse(char C[], int n);

int main() {
  char C[51];
  printf("Enter a string: ");
  cin >> C; // gets(C); doe not work
  Reverse(C, strlen(C));
  printf("Output: %s\n", C);
}

void Reverse(char *C, int n) { /*C[] is equivalent to *C */
  stack<char> S;
  /*TIme and space complexity of both below for loops are O(n)*/
  for (int i = 0; i < n; i++) {
    S.push(C[i]);
  }
  for (int i = 0; i < n; i++) {
    C[i] = S.top();
    S.pop();
  }
}