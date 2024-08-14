#include <stdio.h>
#include <stdlib.h>

// String length recursion
int LengthofString(int n, char *string) {
  if (string[n] == '\0') {
    // printf("%i", n);
    return n;
  }

  LengthofString(n + 1, string);
  // printf("%c",string[n]);
}
// String length iterative
int stringLen(char *str) {
  int length = 0;

  // Loop till the NULL character is found
  while (*str != '\0') {
    length++;

    // Move to the next character
    str++;
  }
  return length;
}
// String length pointer
int stringLenPtr(char *str) {
  // Start pointer pointing at the beginning
  char *ptr = &str[0];

  // Move the pointer until it points to null character
  while (*ptr)
    ptr++;

  // Difference between the address will give the length
  return ptr - str;
}

int main() {
  char *m;

  printf("input string : ");
  scanf("%s", m);
  int len;

  len = printf("%s\n", m) - 1;
  printf("Len in method 1: %d\n", len);

  len = LengthofString(0, m);
  printf("Len in method 2: %d\n", len);

  len = stringLen(m);
  printf("Len in method 3: %d\n", len);

  len = stringLenPtr(m);
  printf("Len in method 4: %d\n", len);

  return 0;
}