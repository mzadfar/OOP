/**
 * @file test340.cpp
 * @author M. Z.
 * @brief Converting base 10 decimal number to other bases
 * @version 0.1
 * @date 2025-02-15
 *
 * @copyright Copyright (c) 2025
 *
 */

#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

#define BASE_2 2
#define BASE_8 8
#define BASE_16 16

string convertBase(uint32_t numToConvert, uint8_t base);
void reverseString(string &inString);

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
  string allValues = "0123456789ABCDEF";

  if (base < 2 || base > 16) {
    printf("Enter a number between 2 and 16\n");
    exit(1);
  }

  do {
    convertedNum += allValues[numToConvert % base];
    numToConvert /= base;

  } while (numToConvert != 0);

  if (base == BASE_16) {
    convertedNum += 'x';
    convertedNum += '0';
  }

  reverseString(convertedNum);
  
  return convertedNum;
}

void reverseString(string &convertedValue) {
  uint32_t stringStart = 0, stringEnd = convertedValue.length() - 1;
  while (stringStart < stringEnd) {
    char temp = convertedValue[stringStart];
    convertedValue[stringStart] = convertedValue[stringEnd];
    convertedValue[stringEnd] = temp;
    stringStart++;
    stringEnd--;
  }
}

// void reverseString(string &str) {
//   int start = 0;
//   int end = str.length() - 1;

//   while (start < end) {
//     swap(str[start], str[end]);
//     start++;
//     end--;
//   }
// }

// string reverseString(string &inString) {
//   int lenInString = size(inString);
//   string outString;

//   for (int32_t i = lenInString; i >= 0; i--) {
//     outString += inString[i];
//   }
//   return outString;
// }