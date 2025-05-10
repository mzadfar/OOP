#include <stdio.h>

#define bool int

/* Function to check if x is power of 2*/
bool isPowerOfTwo(int x) {
  /* First x in the below expression is for the case when x is 0 */
  return (x != 0) && ((x & (x - 1)) == 0);
}

int main() {
  isPowerOfTwo(31) ? printf("Yes\n") : printf("No\n");
  isPowerOfTwo(64) ? printf("Yes\n") : printf("No\n");
  return 0;
}
