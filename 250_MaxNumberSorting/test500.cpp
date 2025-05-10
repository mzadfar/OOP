// Underprogress
#include <algorithm>
#include <bitset>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int nCr(int n, int r) {
  if (r > n - r) {
    r = n - r;
  }
  int result = 1;
  for (int i = 0; i < r; ++i) {
    result *= (n - i);
    result /= (i + 1);
  }
  return result;
}

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; ++t) {
    int n, l;
    cin >> n >> l;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    int sb = 0;
    vector<int> pv(30, 0);
    vector<int> vis(30, 0);

    for (int i = 0; i < n; ++i) {
      string b = bitset<32>(arr[i]).to_string();
      int x = b.find('1');
      int j = x;
      while (j >= 0) {
        pv[x - j] += (b[j] - '0') * pow(2, x - j);
        if (b[j] == '1') {
          sb += vis[x - j];
          vis[x - j] = 0;
        }
        j--;
      }
    }

    if (sb < l) {
      cout << "-1" << endl;
      continue;
    }

    sort(pv.rbegin(), pv.rend());

    int res = 1;
    for (int i = 0; i < sb; ++i) {
      if (l <= 0) {
        break;
      }
      if (pv[i] != pv[i + 1]) {
        l--;
      } else {
        int count = 0;
        while (i != sb - 1 && pv[i] == pv[i + 1]) {
          count++;
          i++;
        }
        count++;
        if (l < count) {
          res *= nCr(count, l);
          break;
        }
        l -= count;
      }
    }

    cout << res << endl;
  }

  return 0;
}
