// C program for the above approach
#include <stdio.h>

int FlippedCount(int a, int b) {
  // Return count of set bits in a XOR b
  int n = a ^ b;
  int count = 0;
  while (n > 0) {
    count++;
    n &= (n - 1);
  }
  return count;
}

int main() {
  int a = 10;
  int b = 20;

  // Function call
  printf("%d\n", FlippedCount(a, b));
  return 0;
}