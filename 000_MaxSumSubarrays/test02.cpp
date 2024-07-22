/* Maimum value of all possible subarrays
Time complexity O(n)*/
#include <iostream>
#include <queue>

using namespace std;

int MaimumSumSubarray(int *arr, int n);

int main() {
  int arr[] = {3, -2, 5, -1};
  cout << MaimumSumSubarray(arr, sizeof(arr) / sizeof(arr[0])) << "\n";
  return 0;
}

int MaimumSumSubarray(int *arr, int n) {
  int ans = arr[0], sum = 0, i;

  for (i = 1; i < n; i++) {
    ans = max(ans, arr[i]);
  }

  if (ans < 0) {
    return ans;
  }

  ans = 0;

  for (i = 0; i < n; i++) {
    if ((sum + arr[i]) > 0) {
      sum += arr[i];
    } else {
      sum = 0;
    }
    ans = max(ans, sum);
  }
  return ans;
}