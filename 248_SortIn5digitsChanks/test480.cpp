#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cout << "Insert number of digits in the array : \n";
  cin >> n;

  cout << "Insert " << n << " digits for the array : \n";
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int max_arr = *max_element(arr.begin(), arr.end());
  int mul = 1;
  int r = 100000;

  while (max_arr) {
    sort(arr.begin(), arr.end(),
         [mul, r](int x, int y) { return (x / mul) % r < (y / mul) % r; });

    cout << "The result is: " << endl;
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;

    mul *= r;
    max_arr /= r;
  }

  return 0;
}