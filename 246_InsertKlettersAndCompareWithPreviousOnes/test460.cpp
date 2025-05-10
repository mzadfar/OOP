#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int n;
  cout << "Insert number of letter to be inserted: \n";
  cin >> n;
  vector<string> s;
  s.reserve(n); // Reserve space for n elements

  for (int i = 0; i < n; ++i) {
    string input;
    printf("Insert number %d test case: \n", i + 1);
    cin >> input;
    s.push_back(input);
    int count = 0;
    for (int j = 0; j < i; ++j) {
      if (s[j] < s[i]) {
        count++;
      }
    }
    cout << "Comparison of this letter to the previous one is: " << count
         << endl;
  }
  return 0;
}
