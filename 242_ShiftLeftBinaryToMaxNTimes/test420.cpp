
#include <iostream>
#include <string>

using namespace std;

int main() {
  int t;
  cout << "Insert number of test cases: \n";
  cin >> t;
  int c = 0;
  while (t != 0) {
    int n, k;
    printf("Insert binary string size and number of maximum repeting for %dst "
           "test case: \n",
           ++c);
    cin >> n >> k;
    string s;
    printf("Insert binary string by size %d: \n", n);
    cin >> s;
    string max = "";
    int p = -1;
    int d = -1;

    for (int i = 0; i < n; i++) {
      if (max < s) {
        max = s;
        d = i;
      } else if (max == s) {
        p = i - d;
        break;
      }
      s = s.substr(1) + s[0];
    }
    cout << "Number of cyclic shift is: ";
    if (p == -1) {
      cout << d + (k - 1) * n << endl;
    } else {
      cout << d + (k - 1) * p << endl;
    }
    t--;
  }
  return 0;
}
