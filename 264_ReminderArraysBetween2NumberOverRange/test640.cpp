#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int a, b;
  cout << "Enter 2 numbers to be evaluated: \n";
  cin >> a >> b;
  int l, r;
  cout << "Enter 2 numbers as range of test: \n";
  cin >> l >> r;
  int k;
  cout
      << "Enter desired reminder of divinding 1st set of number oevr the range "
         "of 2nd set of numbers: \n";
  cin >> k;
  int x = a % b;

  if (a < b) {
    int res;
    if (l <= a + 1) {
      res = r - a;
    } else {
      res = r - l + 1;
    }
    if (b > l && b <= r) {
      res -= 1;
    }
    if (res < 0) {
      res = 0;
    }
    cout << "The length of response array is: " << res << endl;
    cout << "The elements of response array are: ";
    if (res > k) {
      cout << -1 << endl;
    } else {
      for (int i = a + 1; i <= r; ++i) {
        if (i != b) {
          cout << i << " ";
        }
      }
      cout << endl;
    }
  } else {
    int st = 1;
    int end = r;
    if (r > floor(sqrt(a - x))) {
      end = static_cast<int>(floor(sqrt(a - x)));
    }
    vector<int> res;
    vector<int> res1;
    if (st == end + 1) {
      if ((a - x) % st == 0) {
        res.push_back(st);
      }
    }
    for (int i = st; i <= end; ++i) {
      if ((a - x) % i == 0 && i >= l && i <= r && i != b && i > x) {
        res.push_back(i);
      }
      if ((a - x) % i == 0 && (a - x) / i >= l && (a - x) / i <= r &&
          (a - x) / i != b && (a - x) / i >= x && (a - x) / i != end) {
        res1.insert(res1.begin(), (a - x) / i);
      }
    }
    res.insert(res.end(), res1.begin(), res1.end());
    cout << "The length of response array is: " << res.size() << endl;
    cout << "The elements of response array are: ";
    if (res.size() > k) {
      cout << -1 << endl;
    } else {
      for (int v : res) {
        cout << v << " ";
      }
      cout << endl;
    }
  }

  return 0;
}