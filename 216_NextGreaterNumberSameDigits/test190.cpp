// C++ implementation to find the next higher number
// using atmost one swap operation
#include <bits/stdc++.h>

using namespace std;

// function to find the next higher number
// using atmost one swap operation
string nxtHighUsingAtMostOneSwap(string num) {
  int l = num.size();

  // to store the index of the largest digit
  // encountered so far from the right
  int posRMax = l - 1;

  // to store the index of rightmost digit
  // which has a digit greater to it on its
  // right side
  int index = -1;

  // finding the 'index' of rightmost digit
  // which has a digit greater to it on its
  // right side
  for (int i = l - 2; i >= 0; i--) {
    if (num[i] >= num[posRMax])
      posRMax = i;

    // required digit found, store its
    // 'index' and break
    else {
      index = i;
      break;
    }
  }

  // if no such digit is found which has a
  // larger digit on its right side
  if (index == -1)
    return "Not Possible";

  // to store the index of the smallest digit
  // greater than the digit at 'index' and right
  // to it
  int greatSmallDgt = -1;

  // finding the index of the smallest digit
  // greater than the digit at 'index'
  // and right to it
  for (int i = l - 1; i > index; i--) {
    if (num[i] > num[index]) {
      if (greatSmallDgt == -1)
        greatSmallDgt = i;
      else if (num[i] <= num[greatSmallDgt])
        greatSmallDgt = i;
    }
  }

  // swapping the digits
  char temp = num[index];
  num[index] = num[greatSmallDgt];
  num[greatSmallDgt] = temp;

  // required number
  return num;
}

// Driver program to test above
int main() {
  string num = "218765";
  cout << "Original number: " << num << endl;
  cout << "Next higher number: " << nxtHighUsingAtMostOneSwap(num) << "\n";
  return 0;
}
