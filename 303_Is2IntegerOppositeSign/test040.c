#include <stdio.h>

int main() {
  int x = 4;
  int y = -8;

  // true if `x` and `y` have opposite signs
  int isOpposite = (x ^ y);

  if (isOpposite < 0) {
    printf("Have opposite signs\n");
  } else {
    printf("Not have opposite signs\n");
  }

  return 0;
}
