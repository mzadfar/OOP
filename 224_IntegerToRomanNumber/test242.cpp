#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

string integerToRoman(int num) {
  unordered_map<int, char> roman; // move outside
  roman[1] = 'I';
  roman[5] = 'V';
  roman[10] = 'X';
  roman[50] = 'L';
  roman[100] = 'C';
  roman[500] = 'D';
  roman[1000] = 'M';
  roman[5000] = 'G';
  roman[10000] = 'H';

  string tmp = to_string(num);
  const int numDigits = tmp.length();

  string res = "";
  for (int i = 0; i < numDigits; ++i) {
    const char src = tmp[i];        // orig
    const int number = (src - '0'); // convert to integer
    const int place = (numDigits - 1) - i;
    const int absolute = pow(10, place);

    if (number == 9) {
      res.append(1, roman[absolute]);
      res.append(1, roman[(number + 1) * absolute]);
    } else if (number >= 5) {
      res.append(1, roman[5 * absolute]);
      res.append(number - 5, roman[absolute]);
    } else if (number >= 4) {
      res.append(1, roman[absolute]);
      res.append(1, roman[5 * absolute]);
    } else {
      res.append(number, roman[absolute]);
    }
  }
  return res;
}

int main() {
  cout << integerToRoman(3549) << endl;
  return 0;
}
