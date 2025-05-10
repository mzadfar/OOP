#include <stdio.h>

int add(int a, int b) {
  int carry = a & b;
  int result = a ^ b;
  while (carry != 0) {
    int shiftedcarry = carry << 1;
    carry = result & shiftedcarry;
    result ^= shiftedcarry;
  }
  return result;
}

int divide(int nu, int de) {

  int temp = 1;
  int quotient = 0;

  while (de <= nu) {
    de <<= 1;
    temp <<= 1;
  }

  // printf("%d %d\n",de,temp,nu);
  while (temp > 1) {
    de >>= 1;
    temp >>= 1;

    if (nu >= de) {
      nu -= de;
      // printf("%d %d\n",quotient,temp);
      quotient += temp;
    }
  }

  return quotient;
}

int multiply(int a, int b) {

  int result = 0;
  while (b != 0) // Iterate the loop till b == 0
  {
    if (b & 1) // Bitwise & of the value of b with 1
    {
      result = add(result, a); // Add a to result if b is odd .
    }
    a <<= 1; // Left shifting the value contained in 'a' by 1
             // Multiplies a by 2 for each loop
    b >>= 1; // Right shifting the value contained in 'b' by 1.
  }

  return result;
}

int subtract(int x, int y) {
  // Iterate till there
  // is no carry
  while (y != 0) {
    // borrow contains common
    // set bits of y and unset
    // bits of x
    int borrow = (~x) & y;

    // Subtraction of bits of x
    // and y where at least one
    // of the bits is not set
    x = x ^ y;

    // Borrow is shifted by one
    // so that subtracting it from
    // x gives the required sum
    y = borrow << 1;
  }
  return x;
}
/*
int subtract(int x, int y)
{
    if (y == 0)
        return x;
    return subtract(x ^ y, (~x & y) << 1);
}
*/

int remaind(int num, int divisor) {

  // While divisor is smaller
  // than n, keep subtracting
  // it from num
  while (num >= divisor)
    num = subtract(num, divisor);

  return num;
}

int main() {
  int a = 41;
  int b = 20;

  printf("a + b =  %d\n", add(a, b));
  printf("a - b =  %d\n", subtract(a, b));
  printf("a * b =  %d\n", multiply(a, b));
  printf("a / b =  %d\n", divide(a, b));
  printf("a %% b =  %d\n", remaind(a, b));
  return 0;
}
