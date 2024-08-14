// C code for swapping given bits of a number
#include <stdint.h>
#include <stdio.h>
int swapBits(int n, int p1, int p2) {
  // left-shift 1 p1 and p2 times
  // and using XOR
  if (((n & (1 << p1)) >> p1) ^ ((n & (1 << p2)) >> p2)) {
    n ^= 1 << p1;
    n ^= 1 << p2;
  }
  return n;
}

void swapBits1(uint8_t *b) {
  // Answer: TODO
  if (((*b & (1 << 3)) >> 3) ^ ((*b & (1 << 7)) >> 7)) {
    *b ^= 1 << 3;
    *b ^= 1 << 7;
  }
}

int main() {
  uint8_t a = 28;
  printf("Result = %d\n", swapBits(a, 3, 7));
  swapBits1(&a);
  printf("Result = %d\n", a);
  return 0;
}
