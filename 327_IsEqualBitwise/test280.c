#include <stdio.h>

int checkForEquality(int x, int y) { return !(x ^ y); }

int main(void) {
  int x = 10, y = 10;

  if (checkForEquality(x, y)) {
    printf("x=%d is equal to y=%d\n", x, y);
  } else {
    printf("x=%d is not equal to y=%d\n", x, y);
  }

  return 0;
}