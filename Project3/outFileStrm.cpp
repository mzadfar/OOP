#include <iostream>
#include <fstream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: Develop a simple program to write two integers 
//into a file

int main()
{
int a;
int b;
ofstream outFile;

a = 104;
b = -19;

outFile.open("output.txt");
if (outFile.fail())
{
  cout << "Unable to open output file" << endl;
  exit(1);
}
outFile << "a: " << a << endl;
outFile << "b: " << b << endl;

outFile.close();

return (0);
}







