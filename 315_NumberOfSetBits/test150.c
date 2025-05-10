#include <stdio.h>

int main() {
  int n = 17;
  printf("The total number of set bits in %d is: %d\n", n,
         __builtin_popcount(n));

  return 0;
}