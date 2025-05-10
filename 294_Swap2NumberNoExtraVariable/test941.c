#include <stdio.h>

void swap(int a, int b) {
  // same as a = a + b
  a = (a & b) + (a | b);
  // same as b = a - b
  b = a + (~b) + 1;
  // same as a = a - b
  a = a + (~b) + 1;
  printf("After swapping: a = %d , b = %d \n", a, b);
}

int main() {
  int a[2];
  printf("Enter 2 numbers with space between: ");
  for (int i = 0; i < 2; i++)
    scanf("%d", &a[i]);

  int x = a[0], y = a[1];
  swap(x, y);
  // printf("After Swapping: x = %d, y = %d\n", x, y);
  return 0;
}
