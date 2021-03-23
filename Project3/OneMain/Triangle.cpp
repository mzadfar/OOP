#include <iostream>
#include <cmath> //for sqrt
using namespace std;

#include "Triangle.h"

double Triangle::computeArea()
{
  return ((len * wid) / 2.0);
}

double Triangle::computeCircumference()
{
  return (len + wid + sqrt(len * len + wid * wid));
}

void Triangle::print()
{
  cout << "Tri Len: " << len << " Wid: " << wid << endl;
}
