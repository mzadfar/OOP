#include <stdio.h>

int main() {
  int n = 20;

  printf("Reseting the rightmost set bit in %d will result %d\n", n,
         (n & (n - 1)));

  return 0;
}
