#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum
// jumps to reach end of array
int findMaxJumps(int arr[], int N) {
  // Stores the jumps needed
  // to reach end from each index
  int dp[N] = {0};
  int ans = 0;

  // Traverse the array
  for (int i = N - 1; i >= 0; i--) {
    dp[i] = arr[i];
    int j = i + arr[i];

    // Check if j is less
    // than N
    if (j < N) {

      // Add dp[j] to the
      // value of dp[i]
      dp[i] = dp[i] + dp[j];
    }

    // Update the value
    // of ans
    ans = max(ans, dp[i]);
  }

  // Print the value of ans
  return ans;
}

int main() {

  int arr[] = {1, 2, 5, 6, 7};
  int N = sizeof(arr) / sizeof(arr[0]);

  cout << "Maximum jump to end of array: " << findMaxJumps(arr, N) << "\n";

  return 0;
}