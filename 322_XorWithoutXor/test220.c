#include <stdio.h>
#include <stdlib.h>

// Function to find XOR of two numbers without using XOR operator
int findBits(int x, int y) { return (x | y) - (x & y); }

int main() {
  int x = 65;
  int y = 80;

  printf("\nXOR of %d ^ %d = %d = %d\n", x, y, x ^ y, findBits(x, y));

  return 0;
}