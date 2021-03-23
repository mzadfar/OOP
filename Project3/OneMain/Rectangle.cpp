#include <iostream>
using namespace std;

#include "Rectangle.h"

double Rectangle::computeArea()
{
  return (len * wid);
}

double Rectangle::computeCircumference()
{
  return (2 * len + 2 * wid);
}

void Rectangle::print()
{
  cout << "Rect Len: " << len << " Wid: " << wid << endl;
}
