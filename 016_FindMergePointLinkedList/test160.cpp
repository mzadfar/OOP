/* Merge 2 arrays and sort the result */
#include <iostream>
#include <set>

using namespace std;

struct Node {
  int data;
  Node *next;
};

int Length(Node *head);
Node *FindMergePoint1stMethod(Node *A, Node *B); /*Brute force approach*/
Node *FindMergePoint2ndMethod(Node *A, Node *B); /*Using memory in brute force*/
Node *FindMergePoint3rdMethod(Node *A, Node *B); /*The best approach to solve*/

int main() {
  Node *head1 = NULL;
  Node *head2 = NULL;
  Node *temp[7];
  for (int i = 0; i < 7; i++) {
    temp[i] = new Node();
  }

  temp[0]->data = 4;
  temp[0]->next = temp[1];
  temp[1]->data = 6;
  temp[1]->next = temp[2];
  temp[2]->data = 7;
  temp[2]->next = temp[3];
  temp[3]->data = 1;
  temp[3]->next = NULL;
  temp[4]->data = 9;
  temp[4]->next = temp[5];
  temp[5]->data = 3;
  temp[5]->next = temp[6];
  temp[6]->data = 5;
  temp[6]->next = temp[2];

  head1 = temp[0];
  head2 = temp[5];
  Node *C = FindMergePoint3rdMethod(head1, head2);
  cout << C->data << "\n";
  return 0;
}

int Length(Node *head) {
  int len = 0;
  while (head != NULL) {
    len++;
    head = head->next;
  }
  return len;
}

Node *FindMergePoint1stMethod(Node *A, Node *B) {
  int m = Length(A); /*O(m)*/
  int n = Length(B); /*O(n)*/
  Node *head2 = B;
  for (int i = 0; i < m; i++) {
    B = head2;
    for (int j = 0; j < n; j++) {
      if (A == B) {
        return A;
      }
      B = B->next;
    }
    A = A->next;
  }
  return NULL;
}
Node *FindMergePoint2ndMethod(Node *A, Node *B) {
  int m = Length(A); /*O(m)*/
  int n = Length(B); /*O(n)*/
  set<Node *> addresses;
  for (int i = 0; i < n; i++) { /*O(n log n)*/
    addresses.insert(B);        /*O(log n)*/
    B = B->next;
  }
  for (int i = 0; i < m; i++) {                 /*O(m log n)*/
    if (addresses.find(A) != addresses.end()) { /*O(log n)*/
      return A;
    }
    A = A->next;
  }
  return NULL;
}

Node *FindMergePoint3rdMethod(Node *A, Node *B) {
  int m = Length(A); /*O(m)*/
  int n = Length(B); /*O(n)*/
  int d = n - m;
  if (m > n) {
    Node *temp = A;
    A = B;
    B = temp;
    d = m - n;
  }
  int i;
  for (i = 0; i < d; i++) {
    B = B->next;
  }
  while ((A != NULL) && (B != NULL)) {
    if (A == B) {
      return A;
    }
    A = A->next;
    B = B->next;
  }
  return NULL;
}