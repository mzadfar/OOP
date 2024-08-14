#include <stdio.h>

int isKthBitSet(int n, int k) { return (n & (1 << (k - 1))); }

int main() {
  int n = 20;
  int k = 3;

  if (isKthBitSet(n, k) != 0) {
    printf("%d'th bit is set\n", k);
  } else {
    printf("%d'th bit is not set\n", k);
  }

  return 0;
}
