#include <stdio.h>

int main() {
  int a[2];
  printf("Enter 2 numbers with space between: ");
  for (int i = 0; i < 2; i++)
    scanf("%d", &a[i]);

  int x = a[0], y = a[1];
  // Code to swap 'x' and 'y'
  x = x + y; // x now becomes 15
  y = x - y; // y becomes 10
  x = x - y; // x becomes 5
  printf("After Swapping: x = %d, y = %d\n", x, y);
  return 0;
}
