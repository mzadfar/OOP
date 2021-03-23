#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_
#include <iostream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: develop program for header file of a row and column class 
//to access pixels in image in order to modifying pictures on a computer

//Introducing RowColumnClass
class RowColumnClass{
private: 
  int inRow;
  int inCol;

public:
  RowColumnClass();
  RowColumnClass(int inRow, int inCol);

  void setRowCol(int inRow, int inCol);
//  void setRow(int inRow);
//  void setCol(int inCol);

  int getRow(); 
  int getCol();

//  void addRowColTo(RowColumnClass &inRowCol);

//  void printRowCol();
};

#endif
