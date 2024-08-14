#include <iostream>
using namespace std;

int main() {
  char ch = 'Z';

  // for (char ch = 'A'; ch <= 'Z'; ch++) {
  ch = char(ch | ' ');
  cout << ch << endl;
  //}

  // for (char ch = 'a'; ch <= 'z'; ch++) {
  ch = char(ch & '_');
  cout << ch << endl;
  //}
  return 0;
}
