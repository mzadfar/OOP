#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> RotateMatrix(const vector<vector<int>> &matrix, int n) {
  vector<vector<int>> ret(n, vector<int>(n));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ret[i][j] = matrix[n - j - 1][i];
    }
  }

  return ret;
}

int main() {
  vector<vector<int>> array = {
      {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 0, 1, 2}, {3, 4, 5, 6}};

  vector<vector<int>> rotated = RotateMatrix(array, 4);

  // Print the rotated matrix
  for (const auto &row : rotated) {
    for (int num : row) {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}