#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int baseToDecimal(char *number, int baseFrom, int sizeOfNumber) {
  int result = 0;
  int toThePowerOf = 0;

  for (int i = (sizeOfNumber - 2); i >= 0; --i) {

    if (isalpha(number[i])) {
      int charCode = ((int)tolower(number[i])) - 87;
      result += charCode * pow(baseFrom, toThePowerOf);
    } else {
      result += (number[i] - '0') * pow(baseFrom, toThePowerOf);
    }
    toThePowerOf++;
  }

  printf("%s in the base %d equals %d in base 10\n", number, baseFrom, result);
  return result;
}

char *convertBase(unsigned int numberToConvert, int base) {
  char buffer[33]; // 4 bytes plus \0
  char *pConvertedNumber;

  char allValues[] = "0123456789abcdef";

  if (base < 2 || base > 16) {
    printf("Enter a number between 2 and 16\n");
    exit(1);
  }
  pConvertedNumber = &buffer[sizeof(buffer) - 1];

  *pConvertedNumber = '\0';

  do {
    int value = numberToConvert % base;
    pConvertedNumber--;
    *pConvertedNumber = allValues[value]; //'0' + value;
    numberToConvert /= base;
  } while (numberToConvert != 0);

  printf("%s", pConvertedNumber);
  return pConvertedNumber;
}

int main() {
  unsigned int numberOne = 60;
  printf("%d in base 2= ", numberOne);
  convertBase(numberOne, 2);
  printf("\n");

  printf("%d in base 8= ", numberOne);
  convertBase(numberOne, 8);
  printf("\n");

  printf("%d in base 16= ", numberOne);
  convertBase(numberOne, 16);
  printf("\n");

  char numberToConvert[] = "3C";
  baseToDecimal(numberToConvert, 16, sizeof(numberToConvert));
  return 0;
}