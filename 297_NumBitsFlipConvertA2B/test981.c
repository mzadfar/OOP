#include <stdio.h>

int main() {
  int a = 10;
  int b = 20;

  // Function call
  printf("%d\n", __builtin_popcount(a ^ b));
  return 0;
}
