#include <math.h>
#include <stdio.h>
// Returns the position of the rightmost set bit of `n`
int positionOfRightmostSetBit(int n) {
  // if the number is odd, return 1
  if (n & 1) {
    return 1;
  }

  return log2(n & -n) + 1;
}

int main() {
  int n = 20;

  printf("The position of the rightmost set bit is %d\n",
         positionOfRightmostSetBit(n));

  return 0;
}
