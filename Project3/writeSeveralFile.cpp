#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: Develop a simple program to generate several files

int main()
{
ostringstream fnameStream;
string fname;
int i;
ofstream outFile;
for (i = 1; i < 8; i++)
{
  fnameStream.str("");
  fnameStream << "out" << i << ".txt";
  fname = fnameStream.str();

  outFile.open(fname.c_str());
  //outFile << 4;
  outFile.close();
}

return (0);
}
