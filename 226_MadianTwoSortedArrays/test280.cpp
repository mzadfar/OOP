#include <bits/stdc++.h>
using namespace std;

int FindMidian(int *arr1, int n1, int *arr2, int n2) {
  int steps = 0, mid = 0, prev = 0, start1 = 0, start2 = 0;

  while (steps <= (n1 + n2) / 2) {
    prev = mid;
    if ((start1 < n1) && (start2 < n2) && (arr1[start1] > arr2[start2])) {
      mid = arr2[start2];
      start2++;
    } else if ((start1 < n1) && (start2 < n2) &&
               (arr1[start1] <= arr2[start2])) {
      mid = arr1[start1];
      start1++;
    } else if (start1 < n1) {
      mid = arr1[start1];
      start1++;
    } else if (start2 < n2) {
      mid = arr2[start2];
      start2++;
    }
    steps++;
  }

  return mid;
}

int main() {
  int arr1[] = {2, 4, 6};
  int arr2[] = {1, 3, 5, 7};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);
  int n2 = sizeof(arr2) / sizeof(arr2[0]);
  cout << FindMidian(arr1, n1, arr2, n2) << endl;
  return 0;
}
