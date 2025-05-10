/**
 * @file test350.cpp
 * @author M. Z.
 * @brief Converting a number in other bases to decimal
 * @version 0.1
 * @date 2025-02-15
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string>

using namespace std;

#define BASE_2 2
#define BASE_8 8
#define BASE_16 16

int convertToDecimal(const string &numToConvert, uint8_t baseFrom);

int main(void) {
  string numberToConvert = "111100";

  cout << numberToConvert << " in base " << BASE_2 << " equals "
       << convertToDecimal(numberToConvert, BASE_2) << endl;

  numberToConvert = "74";

  cout << numberToConvert << " in base " << BASE_8 << " equals "
       << convertToDecimal(numberToConvert, BASE_8) << endl;

  numberToConvert = "3C";

  cout << numberToConvert << " in base " << BASE_16 << " equals "
       << convertToDecimal(numberToConvert, BASE_16) << endl;

  return 0;
}

int convertToDecimal(const string &numToConvert, uint8_t baseFrom) {
  int result = 0;
  int toThePowerOf = 0;

  for (int i = (numToConvert.length() - 1); i >= 0; --i) {
    if (isalpha(numToConvert[i])) {
      int charCode = tolower(numToConvert[i]) - 'a' + 10;
      result += charCode * pow(baseFrom, toThePowerOf);
    } else {
      result += (numToConvert[i] - '0') * pow(baseFrom, toThePowerOf);
    }
    toThePowerOf++;
  }

  return result;
}
