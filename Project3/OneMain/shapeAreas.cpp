#include <iostream>
using namespace std;

#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "SquareArray.h"

int main()
{
  Square square;
  Triangle triangle;
  Rectangle rectangle;
  SquareArray squareArray;

  square.len = 7;

  triangle.len = 10;
  triangle.wid = 3;
  
  rectangle.len = 10;
  rectangle.wid = 3;

  square.printSquare();
  cout << "  Area: " << square.computeArea() << endl;
  triangle.print();
  cout << "  Area: " << triangle.computeArea() << endl;
  rectangle.print();
  cout << "  Area: " << rectangle.computeArea() << endl;

  squareArray.ary[0].len = 9;
  squareArray.ary[1].len = 5;
  squareArray.ary[2].len = 2;

  cout << "Area Sum: " << squareArray.sumAreas() << endl;
  return (0);
}
