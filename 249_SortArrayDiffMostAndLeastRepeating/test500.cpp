#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int num_iterations;
  cout << "Insert number of test case : \n";
  cin >> num_iterations;

  while (num_iterations--) {
    int n;
    cout << "Insert number of digits in the array : \n";
    cin >> n;

    cout << "Insert " << n << " digits for the array : \n";
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int res = 0;
    int min = -1;
    int current_freq = 0;
    for (int i = 0; i < n; i++) {
      if (i != n - 1 && arr[i] == arr[i + 1]) {
        current_freq += 1;
      } else {
        current_freq += 1;
        if (min == -1) {
          min = current_freq;
        } else {
          if (min > current_freq) {
            min = current_freq;
          } else {
            res = max(res, current_freq - min);
          }
        }
        current_freq = 0;
      }
    }

    if (res > 0) {
      cout << res << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}