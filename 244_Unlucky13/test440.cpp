#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> cache;
unordered_map<long long, long long> cache2;
const long long mod = 1000000009;

long long ans(long long n) {
  if (n < 50000000) {
    if (cache.find(n) != cache.end())
      return cache[n];
    if (n == 0) {
      cache[n] = 1;
      return cache[n];
    }
    if (n == 1) {
      cache[n] = 10;
      return cache[n];
    }
    long long x = ans(n / 2);
    long long y = ans(n / 2 - 1);

    if (n % 2 == 0) {
      cache[n] = (x * x - y * y) % mod;
    } else {
      long long z = ans(n / 2 + 1);
      cache[n] = (x * (z - y)) % mod;
    }
    return cache[n];
  } else {
    if (cache2.find(n) != cache2.end())
      return cache2[n];
    long long temp1 = ans(n / 2);
    long long temp2 = ans(n / 2 - 1);
    if (n % 2 == 0) {
      cache2[n] = (temp1 * temp1 - temp2 * temp2) % mod;
    } else {
      long long temp3 = ans(n / 2 + 1);
      cache2[n] = (temp1 * (temp3 - temp2)) % mod;
    }
    return cache2[n];
  }
}

int main() {
  int in_len;
  cout << "Insert number of test cases: \n";
  cin >> in_len;
  int c = 0;
  for (int i = 0; i < in_len; i++) {
    long long n;
    printf("Insert the number for %dst test case: \n", ++c);
    cin >> n;
    cout << "Number of values without number 13 is: " << ans(n) << endl;
  }
  return 0;
}
