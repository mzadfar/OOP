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
    printf("Insert size 2D matrix for %dst test case: \n", ++c);
    cin >> n;
    printf("Insert elements of %d by %d 2D matrix: \n", n, n);
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
      }
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (int v = i; v < n; v++) {
          for (int k = j; k < n; k++) {
            if (arr[i][j] > arr[v][k]) {
              count++;
            }
          }
        }
      }
    }
    cout << "Number of inversion is: " << count << endl;
    t--;
  }
  return 0;
}