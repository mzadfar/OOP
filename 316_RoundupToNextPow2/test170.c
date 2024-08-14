#include <stdio.h>

unsigned findNextPowerOf2(unsigned n) {
  // decrement `n` (to handle the case when `n` itself
  // is a power of 2)
  n = n - 1;

  // do till only one bit is left
  while (n & n - 1) {
    n = n & n - 1; // unset rightmost bit
  }

  // `n` is now a power of two (less than `n`)

  // return next power of 2
  return n << 1;
}

int main() {
  unsigned n = 127;

  printf("Roundup to %d next power 2: %d\n", n, findNextPowerOf2(n));

  return 0;
}