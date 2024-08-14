#include <stdio.h>
// Here shift operation is twice used as a substitute for array indexing (to
// find 4-bit hamming weights). And one more shift operation uses array indexing
// to perform addition.
int popcountIn(unsigned char x) {

  return ((0x876543210 >>
           (((0x4332322132212110 >> ((x & 0xF) << 2)) & 0xF) << 2)) >>
          ((0x4332322132212110 >> (((x & 0xF0) >> 2)) & 0xF) << 2)) &
         0xf;
}

int main() {
  int a;
  printf("Enter a number: ");
  scanf("%d", &a);

  printf("Hamming distance is: %d\n", popcountIn(a));
  return 0;
}
