// C++ Program for above approach
#include <bits/stdc++.h>
using namespace std;

// Function to calculate roman equivalent
string intToRoman(int num) {
  // Initialize the ans string
  string ans = "";
  // calculate the roman numbers
  while (num) {
    if (num >= 1000) {
      ans += "M";
      num -= 1000;
    }
    // check for all the corner cases like 900,400,90,40,9,4 etc.
    else if (num >= 900 && num < 1000) {
      ans += "CM";
      num -= 900;
    } else if (num >= 500 && num < 900) {
      ans += "D";
      num -= 500;
    } else if (num >= 400 && num < 500) {
      ans += "CD";
      num -= 400;
    } else if (num >= 100 && num < 400) {
      ans += "C";
      num -= 100;
    } else if (num >= 90 && num < 100) {
      ans += "XC";
      num -= 90;
    } else if (num >= 50 && num < 90) {
      ans += "L";
      num -= 50;
    } else if (num >= 40 && num < 50) {
      ans += "XL";
      num -= 40;
    } else if (num >= 10 && num < 40) {
      ans += "X";
      num -= 10;
    } else if (num == 9) {
      ans += "IX";
      num -= 9;
    } else if (num >= 5 && num < 9) {
      ans += "V";
      num -= 5;
    } else if (num == 4) {
      ans += "IV";
      num -= 4;
    } else if (num < 4) {
      ans += "I";
      num--;
    }
  }
  // return the result
  return ans;
}

// Driver program to test above function
int main() {
  int number = 3549;
  cout << intToRoman(number) << "\n";
  return 0;
}
// This code is contributed by Prateek Kumar Singh
