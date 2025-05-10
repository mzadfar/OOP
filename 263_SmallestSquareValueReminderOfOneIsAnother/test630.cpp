#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int num_iterations;
  cout << "Enter number of test cases: \n";
  cin >> num_iterations;

  for (int j = 0; j < num_iterations; ++j) {
    int m, n;
    cout << "Enter 2 space-seperated numbers: \n";
    cin >> m >> n;
    int chk = 0;

    for (int i = static_cast<int>(floor(sqrt(m))); i <= n / 2 + 1; ++i) {
      if ((i * i) % n == m) {
        cout << "The response is: " << i << endl;
        chk = 1;
        break;
      }
    }

    if (chk == 0) {
      cout << "The response is: " << -1 << endl;
    }
  }

  return 0;
}