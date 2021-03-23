#include <iostream>
using namespace std;

#include "Square.h"

double Square::computeArea()
{
  return (len * len);
}

double Square::computeCircumference()
{
  return (4 * len);
}

void Square::printSquare()
{
  cout << "Sq Len: " << len << endl;
}
