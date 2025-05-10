#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  string s;
  int n;
  cout << "Insert a string and with an space distance insert a number smaller "
          "than number of letter in the "
          "string : \n";
  cin >> s >> n;
  vector<string> arr;

  int l = s.length();
  for (size_t i = 0; i < l; ++i) {
    arr.push_back(s);
    s = s.substr(1);
  }

  sort(arr.begin(), arr.end());
  cout << "String " << arr[n - 1] << " is located at position " << n << endl;

  return 0;
}
