#include <stdio.h>

unsigned findPreviousPowerOf2(unsigned n) {
  // do till only one bit is left
  while (n & n - 1) {
    n = n & n - 1; // unset rightmost bit
  }

  // `n` is now a power of two (less than or equal to `n`)
  return n;
}

int main() {
  unsigned n = 127;

  printf("Roundup to %d next power 2: %d\n", n, findPreviousPowerOf2(n));

  return 0;
}