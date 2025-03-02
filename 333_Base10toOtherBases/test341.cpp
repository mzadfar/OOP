/**
 * @file test341.cpp
 * @author M. Z.
 * @brief Converting base 10 decimal number to other bases
 * @version 0.1
 * @date 2025-02-15
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

#define BASE_2 2
#define BASE_8 8
#define BASE_16 16

string convertBase(uint32_t numToConvert, uint8_t base);

int main(void) {
  uint32_t numberToConvert = 60;

  cout << numberToConvert << " in base " << BASE_2 << " is "
       << convertBase(numberToConvert, BASE_2) << endl;

  cout << numberToConvert << " in base " << BASE_8 << " is "
       << convertBase(numberToConvert, BASE_8) << endl;

  cout << numberToConvert << " in base " << BASE_16 << " is "
       << convertBase(numberToConvert, BASE_16) << endl;

  return 0;
}

string convertBase(uint32_t numToConvert, uint8_t base) {
  string convertedNum = "";
  char allVlues[] = "0123456789ABCDEF";

  if (base < 2 || base > 16) {
    printf("Enter a number between 2 and 16\n");
    exit(1);
  }

  do {
    int value = numToConvert % base;
    convertedNum += allVlues[value] ;
    numToConvert /= base;
  } while (numToConvert != 0);

  if (base == BASE_16) {
    convertedNum += 'x';
    convertedNum += '0';
  }

  reverse(convertedNum.begin(), convertedNum.end());

  return convertedNum;
}