#include <cmath>
#include <iostream>
#include <stdlib.h>

using namespace std;

int BulbSwitch(string str);

int main() {
  string str = "0100";
  cout << BulbSwitch(str) << "\n";
  return 0;
}

int BulbSwitch(string str) {
  int res = 0, state = 0;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] != str[state]) {
      state = 1 - state;
      res++;
    }
  }
  return res;
}
