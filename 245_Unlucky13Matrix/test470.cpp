#include <iostream>
#include <vector>

using namespace std;

static long MOD = (long)(1e9 + 9);

static vector<vector<long>> multiply(const vector<vector<long>> &A,
                                     const vector<vector<long>> &B) {
  vector<vector<long>> C(2, vector<long>(2, 0));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        C[i][k] += (A[i][j] * B[j][k]) % MOD;
        if (C[i][k] >= MOD) {
          C[i][k] -= MOD;
        }
        if (C[i][k] < 0) {
          C[i][k] += MOD;
        }
      }
    }
  }
  return C;
}

static long power(vector<vector<long>> &arr, long n) {
  vector<vector<long>> ans = {{1, 0}, {0, 1}};
  while (n != 0) {
    if (n % 2 != 0) {
      ans = multiply(ans, arr);
    }
    n = n / 2;
    arr = multiply(arr, arr);
  }
  return ans[0][0];
}

int main() {
  int t;
  cout << "Insert number of test cases: \n";
  cin >> t;
  int c = 0;
  while (t != 0) {
    long n;
    printf("Insert the number for %dst test case: \n", ++c);
    cin >> n;
    vector<vector<long>> arr = {{10, -1}, {1, 0}};
    long ans = power(arr, n);
    cout << "Number of values without number 13 is: " << ans << endl;
    t--;
  }
  return 0;
}
