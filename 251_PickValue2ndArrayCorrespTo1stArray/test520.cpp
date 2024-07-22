#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, m, g;
  cout << "Insert length for time of raining array, wet clothes array, and "
          "pickup clothes limitation : \n";
  cin >> n >> m >> g;

  cout << "Insert elements for time of raining array: \n";
  vector<int> t(n);
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  cout << "Insert elements of wet clothes array: \n";
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }

  int res = 0;
  int max_dry = 0;
  for (int i = 1; i < n; i++) {
    max_dry = max(max_dry, t[i] - t[i - 1]);
  }

  for (int i = 0; i < m; i++) {
    if (a[i] <= max_dry) {
      res++;
    }
  }

  cout << res << endl;

  return 0;
}