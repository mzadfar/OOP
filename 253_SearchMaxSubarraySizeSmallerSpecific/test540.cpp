#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, x;
  cout << "Enter length of array and the number to be bigger than "
          "combination: \n";
  cin >> n >> x;

  cout << "Enter lelements of array with lenght of " << n << " here \n";
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<int> arr(n + 1, 0);
  int chk = 0;
  for (int i = 0; i < n; ++i) {
    arr[i + 1] = arr[i] + a[i];
    if (a[i] > x) {
      chk = 1;
    }
  }

  if (chk == 1) {
    cout << "-1" << endl;
  } else if (arr[n] < x) {
    cout << n << endl;
  } else {
    int si = 1;
    int li = n;
    while (si <= li) {
      int mid = (si + li) / 2;
      chk = 0;
      int j = mid;
      while (j < n + 1) {
        if (arr[j] - arr[j - mid] > x) {
          break;
        }
        j++;
      }
      if (j == n + 1) {
        si = mid + 1;
      } else {
        li = mid - 1;
      }
    }

    cout << "Response is: " << si - 1 << endl;
  }

  return 0;
}