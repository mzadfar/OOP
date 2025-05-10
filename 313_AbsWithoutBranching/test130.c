#include <stdio.h>

int main() {
  int n = -6;

  printf("abs(%d) is %d\n", n, ((n >> 31) & (~n + 1)) | ((~n >> 31) & n));

  return 0;
}
