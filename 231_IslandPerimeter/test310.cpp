#include <bits/stdc++.h>
using namespace std;

int islandPerimeter(vector<vector<int>> &grid) {
  int m = grid.size();
  if (m == 0)
    return 0;
  int n = grid[0].size();
  if (n == 0)
    return 0;

  int islands = 0;
  int sharedEdges = 0;

  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      if (grid[i][j]) {
        ++islands;
        /*
        count shared edges,
        note that we only look down and right
        */
        if (i + 1 < m && grid[i + 1][j])
          ++sharedEdges;
        if (j + 1 < n && grid[i][j + 1])
          ++sharedEdges;
      }
    }
  }

  return islands * 4 - sharedEdges * 2;
}
int main() {
  vector<vector<int>> arr = {
      {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 1, 1, 1, 0}, {0, 0, 1, 0, 0}};

  cout << islandPerimeter(arr) << "\n";
  return 0;
}