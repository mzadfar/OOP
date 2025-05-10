#include <stdio.h>

int countSetBits(int n) {
  int count = 0;

  for (int i = 0; i < 32; i++) {
    count += (n & 1); // check last bit
    n >>= 1;
  }

  return count;
}

int main() {
  int n = -1;

  printf("The total number of set bits in %d is: %d\n", n, countSetBits(n));

  return 0;
}