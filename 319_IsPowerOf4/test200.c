#include <stdio.h>

int checkPowerOf4(unsigned n) {
  // return true if `n` is a power of 2, and its only
  // set bit is present at even position
  return n && !(n & (n - 1)) && !(n & 0xAAAAAAAA);
}

int main() {
  unsigned n = 256;

  if (checkPowerOf4(n) != 0) {
    printf("%d is power of 4\n", n);
  } else {
    printf("%d is not power of 4\n", n);
  }

  return 0;
}