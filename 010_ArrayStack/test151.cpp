/*Linked list: Insert stack (LIFO)*/
#include <iostream>

using namespace std;

#define MAX_SIZE 101

class Stack {
private:
  int A[MAX_SIZE];
  int top;

public:
  Stack() { top = -1; }

  void Push(int data) {
    if (top == (MAX_SIZE - 1)) {
      printf("Error: stack overflow\n");
      return;
    }
    // top++;
    // A[top] = data;
    /*Below line works instead of 2 above lines*/
    A[++top] = data;
  }

  void Pop(void) {
    if (top == -1) {
      printf("Error: no element to pop\n");
      return;
    }
    top--;
  }

  int Top(void) { return A[top]; }

  void Print(void) {
    int i;
    printf("Stack: ");
    for (i = 0; i <= top; i++) {
      printf("%d ", A[i]);
    }
    printf("\n");
  }
};

int main() {
  Stack S;

  S.Push(2);
  S.Print();
  S.Push(5);
  S.Print();
  S.Push(10);
  S.Print();
  S.Pop();
  S.Print();
  S.Push(12);
  S.Print();
}
