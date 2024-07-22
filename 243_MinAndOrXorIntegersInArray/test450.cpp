#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cout << "Insert number of test cases: \n";
  cin >> t;
  int c = 0;
  while (t != 0) {
    int n;
    printf("Insert the size of array for %dst test case: \n", ++c);
    cin >> n;
    vector<int> arr(n);
    printf("Insert the elements of the array by size %d: \n", n);
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int min = arr[0] ^ arr[1];
    for (int i = 1; i < n - 1; ++i) {
      int temp = arr[i] ^ arr[i + 1];
      if (temp < min) {
        min = temp;
      }
    }
    cout << "Minimum value of (Ai and Aj) xor (Ai or Aj) is: " << min << endl;
    t--;
  }
  return 0;
}