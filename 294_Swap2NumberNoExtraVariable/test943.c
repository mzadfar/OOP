#include <stdio.h>

void swap(int *xp, int *yp) {
  if (xp == yp) // Check if the two addresses are same
    return;
  *xp = *xp ^ *yp;
  *yp = *xp ^ *yp;
  *xp = *xp ^ *yp;
}

int main() {
  int a[2];
  printf("Enter 2 numbers with space between: ");
  for (int i = 0; i < 2; i++)
    scanf("%d", &a[i]);

  int x = a[0], y = a[1];
  swap(&x, &y);
  printf("After Swapping: x = %d, y = %d\n", x, y);
  return 0;
}
