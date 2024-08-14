#include <stdio.h>

int main() {
  int number = 0;
  int reverse = 0;
  int remainder = 0;

  printf("Enter a number: ");
  scanf("%d", &number);

  while (number != 0) {
    remainder = number % 10;
    reverse = reverse * 10 + remainder;
    number /= 10;
  }

  printf("Reversed number: %d\n", reverse);

  return 0;
}