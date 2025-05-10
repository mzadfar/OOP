#include <stdio.h>

// Function to find parity of number `n`
int findParity(unsigned n) {
  int parity = 0;

  // run till `n` becomes 0
  while (n) {
    // invert the parity flag
    if (n & 1) {
      if (parity == 0)
        parity = 1;
      else
        parity = 0;
    }

    // right shift `n` by 1 (divide by 2)
    n = n >> 1;
  }

  return parity;
}

int main() {
  unsigned n = 31;

  if (findParity(n) == 1) {
    printf("The parity of %d is odd\n", n);
  } else {
    printf("The parity of %d is even\n", n);
  }

  return 0;
}
