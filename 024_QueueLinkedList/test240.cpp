/* Queue using linked list */
#include <cstddef>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Node {
  int data;
  Node *next;
};

Node *front = NULL;
Node *rear = NULL;

void Enqueue(int data);
void Dequeue();
int Front();
void Print();

int main() {
  cout << "front is: " << Front() << "\n";
  Enqueue(2);
  Print();
  Enqueue(4);
  Print();
  Enqueue(6);
  Print();
  Dequeue();
  Print();
  Enqueue(8);
  Print();
  cout << "front is: " << Front() << "\n";
}

void Enqueue(int data) {
  Node *temp = new Node();
  temp->data = data;
  temp->next = NULL;
  if (front == NULL && rear == NULL) {
    front = rear = temp;
    return;
  }
  rear->next = temp;
  rear = temp;
}

void Dequeue() {
  Node *temp = front;
  if (front == NULL) {
    cout << "Queueos empty\n";
    return;
  }

  if (front == rear) {
    front = rear = NULL;
  } else {
    { front = front->next; }
    delete temp;
  }
}

int Front() {
  if (front == NULL) {
    cout << "Queue is empty";
    return -1;
  }
  return front->data;
}

void Print() {
  Node *temp = front;
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << "\n";
}
