#include <iostream>
using namespace std;

void printRoman(int num) {

  if (num >= 1000) {
    cout << "M";
    printRoman(num - 1000);
  } else if (num >= 900) {
    cout << "CM";
    printRoman(num - 900);
  } else if (num >= 500) {
    cout << "D";
    printRoman(num - 500);
  } else if (num >= 400) {
    cout << "CD";
    printRoman(num - 400);
  } else if (num >= 100) {
    cout << "C";
    printRoman(num - 100);
  } else if (num >= 90) {
    cout << "XC";
    printRoman(num - 90);
  } else if (num >= 50) {
    cout << "L";
    printRoman(num - 50);
  } else if (num >= 40) {
    cout << "XL";
    printRoman(num - 40);
  } else if (num >= 10) {
    cout << "X";
    printRoman(num - 10);
  } else if (num >= 9) {
    cout << "IX";
    printRoman(num - 9);
  } else if (num >= 5) {
    cout << "V";
    printRoman(num - 5);
  } else if (num >= 4) {
    cout << "IV";
    printRoman(num - 4);
  } else if (num >= 1) {
    cout << "I";
    printRoman(num - 1);
  }
}

int main() {
  int number = 3549;
  printRoman(number);
  cout << "\n";
  return 0;
}
