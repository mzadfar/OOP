/*Linked list: Missing number*/
#include <climits>
#include <iostream>

using namespace std;

int main() {
  int n, m = 0, i, j, k, max = INT_MIN;
  ;
  cout << "What is the length of array: \n";
  cin >> n;

  int *arr = new int[n];
  int *res = new int[n];

  printf("Enter %d numbers for array: \n", n);
  for (i = 0; i < n; i++) {
    cin >> arr[i];
    if (i > 0) {
      if ((arr[i] >= 0) && (arr[i - 1] < 0)) {
        m = i;
      }
    }
  }

  if (m == 0) { // All negative elements
    if (arr[0] < 0) {
      for (i = 0; i < n; i++) {
        res[n - i - 1] = arr[i] * arr[i];
      }
    } else {
      for (i = 0; i < n; i++) {
        res[i] = arr[i] * arr[i];
      }
    }
  } else {
    int *res1 = new int[m];
    int *res2 = new int[n - m + 1];

    for (i = 0; i < m; i++) {
      res1[m - i - 1] = arr[i] * arr[i];
    }

    for (i = m; i < n; i++) {
      res2[i - m] = arr[i] * arr[i];
      cout << res2[i - m] << " \n";
    }

    i = j = k = 0;
    while ((i < m) && (j < (n - m))) {
      if (res1[i] < res2[j]) {
        res[k] = res1[i];
        i++;
      } else {
        res[k] = res2[j];
        j++;
      }
      k++;
    }

    while (i < m) {
      res[k] = res1[i];
      i++;
      k++;
    }

    while (j < (n - m)) {
      res[k] = res2[j];
      j++;
      k++;
    }

    delete res1;
    delete res2;
  }

  cout << "The response is: ";
  for (i = 0; i < n; i++) {
    cout << res[i] << " ";
  }
  cout << "\n";

  delete arr;
  delete res;

  return 0;
}