#include <stdio.h>

int main() {
  char ch = 'Z';

  printf("Letter position in alphabet: %d\n", (ch & 31));

  return 0;
}
