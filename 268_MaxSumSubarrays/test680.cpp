// Print largest contiguous array sum
#include <bits/stdc++.h>
using namespace std;

int maxSubArraySum(int a[], int size) {
  vector<int> dp(size, 0);
  dp[0] = a[0];
  int ans = dp[0];
  for (int i = 1; i < size; i++) {
    dp[i] = max(a[i], a[i] + dp[i - 1]);
    ans = max(ans, dp[i]);
  }
  return ans;
}

int main() {
  int n;
  cout << "Enter the length of array: \n";
  cin >> n;

  cout << "Enter " << n << "elements of array: \n";
  int *arr = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cout << "The response is: " << maxSubArraySum(arr, n) << endl;

  return 0;
}
