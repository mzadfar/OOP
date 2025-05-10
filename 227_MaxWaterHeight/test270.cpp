#include <bits/stdc++.h>
using namespace std;

int FindMaxArea(int *arr, int n) {
  int direction, pointing, width, area, start = 0, end = n - 1, maxArea = 0;

  while (start < end) {
    width = end - start;
    area = width * min(arr[start], arr[end]);
    maxArea = max(maxArea, area);
    if (arr[start] < arr[end]) {
      pointing = start;
      direction = 1;
    } else {
      pointing = end;
      direction = -1;
    }
    while ((pointing >= start) && (pointing <= end) &&
           (arr[pointing] > arr[pointing + direction])) {
      pointing += direction;
    }
    pointing += direction;
    if (direction == 1) {
      start = pointing;
    } else {
      end = pointing;
    }
  }

  return maxArea;
}

int main() {
  int arr[] = {1, 2, 5, 3, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << FindMaxArea(arr, n) << endl;
  return 0;
}
