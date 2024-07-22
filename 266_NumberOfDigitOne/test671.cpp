#include <cmath>
#include <iostream>
#include <string>

using namespace std;

int no_one(const string &n) {
  string s = n;
  int l = s.length();
  int res = 0;

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '0') {
      continue;
    }
    if (s[i] > '1') {
      int current_digit = pow(10, s.length() - i - 1);
      int lower_digits = (s.length() - i - 1) * (current_digit / 10);
      lower_digits = (int)(s[i]) * lower_digits;
      int total = lower_digits + current_digit;
      res += total;
    } else {
      if (i == s.length() - 1) {
        res += 1;
      } else {
        string current_digit_str = s.substr(i + 1);
        int current_digit = stoi(current_digit_str) + 1;
        int lower_digits =
            (s.length() - 1 - i) * ((pow(10, s.length() - 1 - i)) / 10);
        int total = lower_digits + current_digit;
        res += total;
      }
    }
  }

  return res;
}

int main() {
  string n;
  cout << "Enter a number: \n";
  cin >> n;
  cout << "The response is: " << no_one(n) << endl;
  return 0;
}