#include <bits/stdc++.h>
using namespace std;

// Function to calculate roman equivalent
string intToRoman(int num) {
  // storing roman values of digits from 0-9
  // when placed at different places
  string m[] = {"", "M", "MM", "MMM"};
  string c[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  string x[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  string i[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

  // Converting to roman
  string thousands = m[num / 1000];
  string hundreds = c[(num % 1000) / 100];
  string tens = x[(num % 100) / 10];
  string ones = i[num % 10];

  string ans = thousands + hundreds + tens + ones;

  return ans;
}

int main() {
  int number = 3549;
  cout << intToRoman(number) << "\n";
  return 0;
}
