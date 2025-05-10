#include <bitset>
#include <iostream>
#include <string>
using namespace std;

// Function to generate binary numbers between 1 and `n` using `std::bitset`
int generate(int n) {
  // run `n` times
  for (int i = 1; i <= n; i++) {
    // convert `i` to an 8–bit binary number
    bitset<8> binary(i);

    // print the current binary number
    cout << binary.to_string() << ' ';
  }
}

int main() {
  int n = 16;
  generate(n);

  return 0;
}