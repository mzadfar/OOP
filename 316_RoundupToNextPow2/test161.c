#include <stdio.h>

unsigned findNextPowerOf2(unsigned n) {
  // decrement `n` (to handle the case when `n` itself
  // is a power of 2)
  n = n - 1;

  // initialize result by 2
  int k = 2;

  // double `k` and divide `n` in half till it becomes 0
  while (n >>= 1) {
    k = k << 1; // double `k`
  }

  return k;
}

int main() {
  unsigned n = 127;

  printf("Roundup to %d next power 2: %d\n", n, findNextPowerOf2(n));

  return 0;
}