#include <iostream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: October 21 2019
//Purpose: develop a simple program to make a 2D array using 
//1D array with dynamic allocation

int main()
{
int *oneDArrayFor2D;
int numRows = 10, numColumns =10;
int oneDIndex;

oneDArrayFor2D = new int[numRows * numColumns];
for (int rInd = 0; rInd < numRows; rInd++)
{
  for (int cInd = 0; cInd < numColumns; cInd++)
  {
    oneDIndex = rInd * numColumns + cInd;
    oneDArrayFor2D[oneDIndex] = rInd * cInd;
  }
}

cout << "val at RC 3 5: " << oneDArrayFor2D[3 * numColumns + 5] << endl;

delete [] oneDArrayFor2D;

oneDArrayFor2D = 0;

return 0;
}
