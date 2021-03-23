#include <iostream>
#include <fstream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: Develop a simple program to read two values 
//from a file, check error, and print sum of them

int main()
{
int a;
int b;

ifstream inFile;
bool validInputFound;

inFile.open("inputVals.txt");

if (inFile.fail())
{
  cout << "Unable to open input file!" << endl;
  exit(1);
}

validInputFound = false;
while (!validInputFound)
{
  inFile >> a;
  if (inFile.eof())
  {
    cout << "EOF before reading a" << endl;
    exit(2);
  }
  else if (inFile.fail())
  {
    inFile.clear();
    inFile.ignore(200, '\n');
  }
  else
  {
    validInputFound = true;
  }
}

cout << "Read a: " << a << endl;

validInputFound = false;
while (!validInputFound)
{
inFile >> b;
if (inFile.eof())
{
cout << "EOF before reading b" << endl;
exit(2);
  }
  else if (inFile.fail())
  {
    inFile.clear();
    inFile.ignore(200, '\n');
  }
  else
  {
    validInputFound = true;
  }
}
cout << "Read b: " << b << endl;
cout << "Sum: " << a + b << endl;

inFile.close();

return (0);
}







