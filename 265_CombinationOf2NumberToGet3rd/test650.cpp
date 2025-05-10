#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

#define dd double

#define ll long long

ll g, x, y;

void extendedEuclid(ll A, ll B) {
  if (B == 0) {
    g = A;
    x = 1;
    y = 0;
  } else {
    extendedEuclid(B, A % B);
    ll temp = x;
    x = y;
    y = temp - (A / B) * y;
  }
}

int main() {
  int q;
  cout << "Enter number of test case: \n";
  cin >> q;
  while (q--) {
    ll a, b, d, e = 0;
    cout << "Enter 3 space-separated numbers to find combinaton last by 2 1st "
            "ones: \n";
    cin >> a >> b >> d;
    extendedEuclid(a, b);
    cout << "The response is: ";
    if (d % g != 0) {
      cout << "0\n";
      continue;
    }
    ll k1 = ceil(dd(-x) * (dd(d) / dd(b))), k2 = floor((dd)y * ((dd)d / (dd)a));
    if (k1 <= k2)
      cout << k2 - k1 + 1 << "\n";
    else
      cout << "0\n";
  }

  return 0;
}