#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int gcd(int x, int y) {
  while (y != 0) {
    int temp = y;
    y = x % y;
    x = temp;
  }
  return x;
}

int lcm(int x, int y) { return (x * y) / (gcd(x, y)); }

int main() {
  int n;
  cout << "Enter length of array: \n";
  cin >> n;

  cout << "Enter " << n << " elements of array: \n";
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int maximum = *max_element(a.begin(), a.end()) + 1;
  vector<int> freq(maximum + 1, 0);

  for (int i : a) {
    freq[i]++;
  }

  vector<int> div(maximum + 1, 0);
  for (int i = 1; i <= maximum; ++i) {
    for (int j = i; j <= maximum; j += i) {
      div[i] += freq[j];
    }
  }

  int queries;
  cout << "Enter number of queries: \n";
  cin >> queries;
  for (int j = 0; j < queries; ++j) {
    cout << "Enter pair number of queries: \n";
    int p, q;
    cin >> p >> q;
    int pq = lcm(p, q);

    int a_val = (p <= maximum) ? div[p] : 0;
    int b_val = (q <= maximum) ? div[q] : 0;
    int ab_val = (pq <= maximum) ? div[pq] : 0;
    cout << "The response is: \n";
    cout << a_val + b_val - ab_val << endl;
  }

  return 0;
}