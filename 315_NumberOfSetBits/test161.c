#include <stdio.h>

// Brian Kernighan’s algorithm
int countSetBits(int n) {
  // `count` stores the total bits set in `n`
  int count = 0;

  while (n) {
    n = n & (n - 1); // clear the least significant bit set
    count++;
  }

  return count;
}

int main() {
  int n = -1;

  printf("The total number of set bits in %d is: %d\n", n, countSetBits(n));

  return 0;
}