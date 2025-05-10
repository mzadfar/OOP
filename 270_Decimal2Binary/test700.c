#include <stdio.h>

int main() {
  char binary[256];
  int decimal;

  do {
    printf("Emter a non-negative number: ");
    scanf("%d", &decimal);
    if (decimal < 0) {
      printf("Integer must be non-negative\n");
    }
  } while (decimal < 0);

  int length = 0;

  do {
    if (decimal % 2 == 0)
      binary[length] = '0';
    else
      binary[length] = '1';
    decimal /= 2;
    length++;
  } while (decimal != 0);

  binary[length] = '\0';

  int middle = length / 2;

  char temp;
  for (int i = 0; i < middle; i++) {
    temp = binary[i];
    binary[i] = binary[length - i - 1];
    binary[length - i - 1] = temp;
  }

  printf("\nbinary number: %s\n", binary);
  return 0;
}