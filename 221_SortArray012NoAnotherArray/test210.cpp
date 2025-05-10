#include <bits/stdc++.h>

using namespace std;

int main() {
  int i = 0, arr[] = {2, 0, 1, 2, 0, 1};
  int n = sizeof(arr) / sizeof(arr[0]);
  int startPointing = 0, endPointing = n - 1;
  while (i <= endPointing) {
    if (arr[i] == 2) {
      arr[i] = arr[endPointing];
      arr[endPointing] = 2;
      endPointing--;
    } else if (arr[i] == 1) {
      i++;
    } else {
      arr[i] = arr[startPointing];
      arr[startPointing] = 0;
      startPointing++;
      i++;
    }
  }

  for (i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  return 0;
}
