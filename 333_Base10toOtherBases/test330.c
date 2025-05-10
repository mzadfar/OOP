/**
 * @file test340.c
 * @author M. Z.
 * @brief Converting base 10 decimal number to other bases
 * @version 0.1
 * @date 2025-02-15
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BASE_2 2
#define BASE_8 8
#define BASE_16 16

char *convertBase(uint32_t numToConvert, uint8_t base);

int main(void) {
  uint32_t numberToConvert = 60;

  printf("%d in base %d is ", numberToConvert, BASE_2);
  convertBase(numberToConvert, BASE_2);
  printf("\n");

  printf("%d in base %d is ", numberToConvert, BASE_8);
  convertBase(numberToConvert, BASE_8);
  printf("\n");

  printf("%d in base %d is ", numberToConvert, BASE_16);
  convertBase(numberToConvert, BASE_16);
  printf("\n");

  return 0;
}

char *convertBase(uint32_t numToConvert, uint8_t base) {
  char buffer[33];
  char *pConvertedNum;
  char allVlues[] = "0123456789ABCDEF";

  if (base < 2 || base > 16) {
    printf("Enter a number between 2 and 16\n");
    exit(1);
  }

  /* point to last index on the character array to store NULL character*/
  pConvertedNum = &buffer[sizeof(buffer) - 1];
  *pConvertedNum = '\0';

  do {
    int value = numToConvert % base;
    pConvertedNum -= 1;

    *pConvertedNum = allVlues[value]; //'0' + value;

    numToConvert /= base;

  } while (numToConvert != 0);

  if (base == BASE_16) {
    pConvertedNum -= 1;
    *pConvertedNum = 'x';
    pConvertedNum -= 1;
    *pConvertedNum = '0';
  }

  printf("%s", pConvertedNum);

  return pConvertedNum;
}