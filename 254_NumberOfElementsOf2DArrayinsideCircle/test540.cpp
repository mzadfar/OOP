#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> &arr, int key) {
  int si = 0;
  int li = arr.size() - 1;
  while (si < li) {
    int mid = (si + li) / 2;
    if (key >= arr[mid]) {
      si = mid + 1;
    } else {
      li = mid;
    }
  }
  return si;
}

int main() {
  int n;
  cout << "Inset number of pairs: \n";
  cin >> n;

  vector<int> d;
  cout << "Inset " << n << " pairs of numbers: \n";
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    d.push_back(x * x + y * y);
  }
  sort(d.begin(), d.end());

  int m;
  cout << "Inset number of test case: \n";
  cin >> m;

  for (int i = 0; i < m; i++) {
    int r;
    cout << "Inset the radius to find pair inside circle: \n";
    cin >> r;
    r = r * r;
    cout << "Response for the test case: \n";
    if (r > d[d.size() - 1]) {
      cout << d.size() << endl;
    } else {
      cout << search(d, r) << endl;
    }
  }

  return 0;
}