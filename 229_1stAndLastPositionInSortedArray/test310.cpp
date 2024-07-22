#include <iostream>
using namespace std;

// if target is present in arr[] then returns
// the index of FIRST occurrence and last occurrence
// of target in arr[0..n-1], otherwise returns -1
int search(int nums[], int n, int target, bool findStartIndex) {
  int ans = -1;
  int start = 0;
  int end = n - 1;
  while (start <= end) {

    // find the middle element
    // might be possible that (start + end)
    // exceeds the range of int in C++
    int mid = start + (end - start) / 2;

    if (target < nums[mid]) {
      end = mid - 1;
    } else if (target > nums[mid]) {
      start = mid + 1;
    } else {
      // potential ans found
      ans = mid;
      if (findStartIndex) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    }
  }

  return ans;
}

int main() {
  int arr[] = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
  int n = sizeof(arr) / sizeof(arr[0]);
  int x = 8;
  int ans[] = {-1, -1};

  // For first occurrence
  ans[0] = search(arr, n, x, true);

  if (ans[0] != -1) {
    // For last occurrence
    ans[1] = search(arr, n, x, false);
  }

  cout << "First Occurrence: " << ans[0] << "\nLast Occurrence: " << ans[1]
       << endl;
  return 0;
}
