#include <stdio.h>

unsigned findPreviousPowerOf2(unsigned n) {
  // initialize result by 1
  int k = 1;

  // double `k` and divide `n` in half till it becomes 0
  while (n >>= 1) {
    k = k << 1; // double `k`
  }

  return k;
}

int main() {
  unsigned n = 127;

  printf("Roundup to %d next power 2: %d\n", n, findPreviousPowerOf2(n));

  return 0;
}