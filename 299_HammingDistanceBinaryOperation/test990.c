#include <stdio.h>

int popcountIn(unsigned char in) {

  unsigned char m1 = 0x55;
  unsigned char m2 = 0x33;
  unsigned char m4 = 0x0f;
  unsigned char B, C = 0;
  unsigned char x = in;

  // If we take an algorithm from http://en.wikipedia.org/wiki/Hamming_weight,
  // then the first sum D=B+C can be written as D = B^C^(B&C << 1), but two
  // following sums are more complicated

  x = (x & (x << 1) & (m1 << 1)) | (m1 & (x ^ (x >> 1)));

  B = x & m2;
  C = (x >> 2) & m2;
  x = B ^ C ^ ((B & C) << 1);

  B = (x & m4) ^ ((x >> 4) & m4);
  C = (x & ((x >> 4) & m4)) << 1;
  x = B ^ C ^ ((B & C) << 1);
  return x;
}

int main() {
  int a;
  printf("Enter a number: ");
  scanf("%d", &a);

  printf("Hamming distance is: %d\n", popcountIn(a));
  return 0;
}
