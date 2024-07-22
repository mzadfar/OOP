/*Linked list: Insert stack (LIFO)*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void Push(int data);
void Pop(void);
int Top(void);
void Print(void);

int main() {
  Push(2);
  Print();
  Push(5);
  Print();
  Push(10);
  Print();
  Pop();
  Print();
  Push(12);
  Print();
}

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