#include <stdio.h>

int main() {
  int n = 5;

  if (n & 1) {
    printf("Number is odd\n");
  } else {
    printf("Number is even\n");
  }

  return 0;
}
