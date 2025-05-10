#include <stdio.h>

int findMin(int x, int y) {
  return y ^ ((x ^ y) & -(x < y));
  // or
  //   return y + ((x - y) & ((x - y) >> 31));
}

int findMax(int x, int y) {
  return x ^ ((x ^ y) & -(x < y));
  // or
  // return x - ((x - y) & ((x - y) >> 31));
}

int main() {
  int x = 2, y = 4;

  printf("min(%d,%d) = %d\n", x, y, findMin(x, y));
  printf("max(%d,%d) = %d\n", x, y, findMax(x, y));

  return 0;
}