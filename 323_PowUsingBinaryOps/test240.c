#include <stdio.h>
#include <stdlib.h>

// Iterative function to calculate `pow(x, n)` using
// binary operators
long power(int x, unsigned n) {
  // initialize result by 1
  long pow = 1L;

  // loop till `n` become 0
  while (n) {
    // if `n` is odd, multiply the result by `x`
    if (n & 1) {
      pow *= x;
    }

    // divide `n` by 2
    n = n >> 1;

    // multiply `x` by itself
    x = x * x;
  }

  // return result
  return pow;
}

int main(void) {
  int x = -2;
  unsigned n = 10;

  printf("pow(%d, %d) = %d\n", x, n, power(x, n));

  return 0;
}