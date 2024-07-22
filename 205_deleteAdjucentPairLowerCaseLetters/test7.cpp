/*Linked list: Balanced parantheses using stack*/
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
  string exp;
  cout << "Enter an expression: ";
  cin >> exp;

  for (int i = 0; i < exp.length() - 1; i++) {
    if (exp[i] == exp[i + 1]) {
      exp.erase(i, 2);
      i--;
      i--;
    }
  }
  if (exp.length() == 0) {
    cout << "Nothing to print";
  } else {
    for (int j = 0; j < exp.length(); j++) {
      cout << exp[j];
    }
  }
  cout << "\n";
}
