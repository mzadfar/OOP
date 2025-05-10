#include <stdio.h>

int main() {
  int x = 4;
  printf("%d + 1 = %d\n", x, -~x);

  x = -5;
  printf("%d + 1 = %d\n", x, -~x);

  x = 0;
  printf("%d + 1 = %d\n", x, -~x);

  return 0;
}
