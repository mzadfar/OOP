#include <stdio.h>

int checkPowerOf8(unsigned n) {
  // return true if `n` is a power of 2, and its only
  // set bit is present at even position
  return n && !(n & (n - 1)) && !(n & 0xB6DB6DB6);
}

int main() {
  unsigned n = 512;

  if (checkPowerOf8(n) != 0) {
    printf("%d is power of 8\n", n);
  } else {
    printf("%d is not power of 8\n", n);
  }

  return 0;
}