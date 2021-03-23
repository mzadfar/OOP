#include <iostream>
#include <sstream>
#include <string>
#include <string>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: Develop a simple program to use atoi and atof,
//after ./outfile put two numbers

int main(int argc, char *argv[])
{
int i;
ostringstream oss;
istringstream iss;
int intVal;
double doubleVal;
//char checkChar;

if (argc != 3)
{
  cout << "ERROR - wrong number of parameters" << endl;
  cout << "Usage: " << argv[0] << " <doubleVal> <intVal>" << endl;
  exit(2);
}

for (i = 1; i < argc; i++)
  oss << " " << argv[i];

iss.str(oss.str());
iss >> doubleVal;
iss >> intVal;

if (iss.fail() || !iss.eof())
{
  cout << "ERROR - invalid format for parameters" << endl;
  cout << "Usage: " << argv[0] << " <doubleVal> <intVal>" << endl;
  exit(2);
}
cout << doubleVal << " / " << intVal << " = " << (doubleVal / intVal) << endl;
return (0);
}
