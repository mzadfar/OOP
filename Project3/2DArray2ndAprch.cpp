#include <iostream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: October 21 2019
//Purpose: develop a simple program to make a 2D array 
//with dynamic allocation

int main()
{
int **valsMatrix;
int numRows = 10, numColumns =10;

valsMatrix = new int*[numRows];

for (int rInd = 0; rInd < numRows; rInd++)
{
  valsMatrix[rInd] = new int[numColumns];
}

for (int rInd = 0; rInd < numRows; rInd++)
{
  for (int cInd = 0; cInd < numColumns; cInd++)
  {
    valsMatrix[rInd][cInd] = rInd * cInd;
  }
}

cout << "val at RC 3 5: " << valsMatrix[3][5] << endl;

for (int rInd = 0; rInd < numRows; rInd++)
{
  delete [] valsMatrix[rInd];
}

delete [] valsMatrix;

return 0;
}
