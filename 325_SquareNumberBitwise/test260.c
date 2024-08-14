#include <stdio.h>

int findSquare(int num) {
  // base case
  if (num < 2) {
    return num;
  }

  // convert the number to positive if it is negative
  if (num < 0)
    num = -num;

  // drop last bit from num (divide it by 2)
  int i = num >> 1;

  // if num is odd
  if (num & 1) {
    return ((findSquare(i) << 2) + (i << 2) + 1);
  }

  // if num is even
  else {
    return (findSquare(i) << 2);
  }
}

int main() {
  int n = 8;

  printf("Square of %d is: %d\n", n, findSquare(n));

  return 0;
}