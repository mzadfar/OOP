#include <stdio.h>

int toggleKthBit(int n, int k) { return n ^ (1 << (k - 1)); }

int main() {
  int n = 20;
  int k = 3;

  printf("Toggling %d'th bit of %d is equal to: %d\n", k, n,
         toggleKthBit(n, k));

  return 0;
}
