#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cout << "Enter number of test case: \n";
  cin >> t;

  for (int j = 0; j < t; j++) {
    int n, k;
    cout << "Enter length of array and number of queries: \n";
    cin >> n >> k;
    cout << "Enter " << n << " elements of array: \n";
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    vector<int> l{1};
    vector<int> r{0};
    vector<pair<int, int>> st(n);
    st[0] = {arr[0], 1};
    int top = 0;

    for (int i = 1; i < n; ++i) {
      int count = 1;
      while (top != -1 && (arr[i] >= st[top].first)) {
        r[r.size() - count] += count;
        count += st[top].second;
        top -= 1;
      }
      top += 1;
      st[top] = {arr[i], count};
      l.push_back(count);
      r.push_back(0);
    }

    int count = 1;
    while (top != -1) {
      r[r.size() - count] += count;
      count += st[top].second;
      top -= 1;
    }

    vector<string> res;
    for (int i = 0; i < k; ++i) {
      int m;
      cout << "Enter query: \n";
      cin >> m;
      m -= 1;
      res.push_back(to_string(l[m] + r[m] - 1));
    }
    cout << "Responses for queries: \n";
    for (const auto &result : res) {
      cout << result << " ";
    }
    cout << endl;
  }

  return 0;
}