#include <iostream>
#include <fstream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: Develop a simple program to read two values 
//from a file and print sum of them

int main()
{
  int a;
  int b;

  ifstream inFile;

  inFile.open("inputVals.txt");

  inFile >> a; //Similar to "cin >> a;"
  cout << "Read a: " << a << endl;

  inFile >> b;
  cout << "Read b: " << b << endl;
  cout << "Sum: " << a + b << endl;

  inFile.close();
  return (0);
}
