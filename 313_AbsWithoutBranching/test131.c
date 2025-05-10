#include <stdio.h>

int main() {
  int n = -6;
  int const mask = n >> sizeof(int) * 8 - 1;

  printf("abs(%d) is %d\n", n, ((n + mask) ^ mask));

  return 0;
}
