#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  map<tuple<int, int, int>, int> cache;

  int n;
  cout << "Enter number of test case: \n";
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a, b, d;
    cout << "Enter 3 space-separated numbers to find combinaton last by 2 1st "
            "ones: \n";
    cin >> a >> b >> d;
    cout << "The response is: ";
    if (cache.count({a, b, d})) {
      cout << cache[{a, b, d}] << endl;
      continue;
    }

    int ma = max(a, b);
    int mi = min(a, b);

    if (d == 0) {
      cout << 1 << endl;
    } else if (mi > d) {
      cout << 0 << endl;
    } else if (ma > d && mi < d) {
      if (d % mi == 0) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else {
      map<int, int> c;
      int count = 0;
      while ((d - (ma * count)) >= 0 &&
             (c.find((d - (ma * count)) % mi) == c.end())) {
        c[(d - (ma * count)) % mi] = (d - (ma * count));
        count++;
      }
      if (c.find(0) == c.end()) {
        cache[{a, b, d}] = 0;
        cout << 0 << endl;
      } else {
        int start = c[0];
        cache[{a, b, d}] = (start / (ma * count)) + 1;
        cout << (start / (ma * count)) + 1 << endl;
      }
    }
  }

  return 0;
}