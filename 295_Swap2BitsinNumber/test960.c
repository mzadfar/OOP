#include <stdio.h>

int swapBits(unsigned int n, unsigned int p1, unsigned int p2) {
  /* Move p1'th to rightmost side */
  unsigned int bit1 = (n >> p1) & 1;

  /* Move p2'th to rightmost side */
  unsigned int bit2 = (n >> p2) & 1;

  /* XOR the two bits */
  unsigned int x = (bit1 ^ bit2);

  /* Put the xor bit back to their original positions */
  x = (x << p1) | (x << p2);

  /* XOR 'x' with the original number so that the
  two sets are swapped */
  unsigned int result = n ^ x;
}

int main() {
  int res = swapBits(28, 0, 3);
  printf("Result = %d ", res);
  return 0;
}
