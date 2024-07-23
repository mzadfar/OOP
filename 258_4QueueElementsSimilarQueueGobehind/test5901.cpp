#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<int> school;
  vector<vector<int>> queue(4, vector<int>());

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    string a, s, r;
    cin >> a >> s >> r;

    if (a[0] == 'E') {

      int student = stoi(s);
      int rating = stoi(r);

      student -= 1;

      if (queue[student].empty()) {
        school.push_back(student);
      }

      queue[student].push_back(rating);
    } else {
      cout << school[0] + 1 << " " << queue[school[0]][0] << endl;
      queue[school[0]].erase(queue[school[0]].begin());

      if (queue[school[0]].empty()) {
        school.erase(school.begin());
      }
    }
  }

  return 0;
}