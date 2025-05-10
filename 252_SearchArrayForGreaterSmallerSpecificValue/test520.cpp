#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int> arr, int key) {
  int si = 0;
  int li = arr.size() - 1;
  while (si < li) {
    int mid = (si + li) / 2;
    if (arr[mid] >= key) {
      li = mid;
    } else {
      si = mid + 1;
    }
  }
  return li;
}

int main() {
  int n;
  cout << "Enter length of array: \n";
  cin >> n;

  cout << "Enter elements of the array: \n";
  vector<int> arr;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end());

  int q;
  cout << "Enter number of queries: \n";
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y;
    cout << "Enter 0 or 1 for less or greater than 2nd number which should be "
            "entered with an space: \n";
    cin >> x >> y;
    y += x;
    cout << "The response is: ";
    if (y > arr[arr.size() - 1]) {
      cout << "0" << endl;
    } else if (y < arr[0]) {
      cout << arr.size() << endl;
    } else {
      int index = search(arr, y);
      cout << n - index << endl;
    }
  }

  return 0;
}