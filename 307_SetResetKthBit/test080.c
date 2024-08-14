#include <stdio.h>

int turnOnKthBit(int n, int k) { return n | (1 << (k - 1)); }

int turnOffKthBit(int n, int k) { return n & ~(1 << (k - 1)); }

int main() {
  int n = 20;
  int k = 4;

  printf("Turning %d'th bit in number %d on will result: %d\n", k, n,
         turnOnKthBit(n, k));

  n = turnOnKthBit(n, k);

  printf("Turning %d'th bit in number %d off will result: %d\n", k, n,
         turnOffKthBit(n, k));

  return 0;
}
