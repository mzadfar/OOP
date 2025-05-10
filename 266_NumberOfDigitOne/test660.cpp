#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  int countDigitOne(int n) {
    int ret = 0;
    for (long long int i = 1; i <= n; i *= (long long int)10) {
      int a = n / i;
      int b = n % i;
      int x = a % 10;
      if (x == 1) {
        ret += (a / 10) * i + (b + 1);
      } else if (x == 0) {
        ret += (a / 10) * i;
      } else {
        ret += (a / 10 + 1) * i;
      }
    }
    return ret;
  }
};
int main() {
  int n;
  cout << "Enter a number: \n";
  cin >> n;
  Solution ob;
  cout << "The response is: " << (ob.countDigitOne(n)) << endl;
}