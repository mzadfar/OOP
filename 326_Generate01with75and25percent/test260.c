#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Return 0 and 1 with 75% and 25% probability, respectively, using the
// specified function, left shift operator, and bitwise XOR operator
int generate() { return ((rand() << 1) ^ rand()) == 0; }

int main() {
  srand(time(NULL));
  printf("Return 0 and 1 with 75 and 25 percent probability: %d\n", generate());

  return 0;
}