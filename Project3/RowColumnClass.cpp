#include <iostream>
#include "constants.h"
#include "RowColumnClass.h"

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: develop program for member functions a row and column class 
//to access pixels in image in order to modifying pictures on a computer

//Implementing functions of RowColumnClass
//Default constructor that sets the row and column values
//of the object to -99999
RowColumnClass::RowColumnClass()
{
  inRow = ROW_INITIAL_VAL;
  inCol = COL_INITIAL_VAL;
}

//Value constructor that sets the row and column values
//of the object to the input values
RowColumnClass::RowColumnClass(int inRowNew, int inColNew)
{
  inRow = inRowNew;
  inCol = inColNew;
}

//A public fuction to set the row and column values of the object
//to the input values
void RowColumnClass::setRowCol(int inRowNew, int inColNew)
{
  inRow = inRowNew;
  inCol = inColNew;
}
/*
//A public fuction to set the row value of the object
//to the input values
void RowColumnClass::setRow(int inRowNew)
{
  inRow = inRowNew;
}

//A public fuction to set the column value of the object
//to the input values
void RowColumnClass::setCol(int inColNew)
{
  inCol = inColNew;
}*/

//A public fuction to return the row value of the object
//to the caller
int RowColumnClass::getRow() 
{ 
  return inRow;
}

//A public fuction to return the column value of the object
//to the caller
int RowColumnClass::getCol() 
{ 
  return inCol; 
}
/*
//A public function to add the row and column index values in the input
//parameter to the row and column index of the called object
void RowColumnClass::addRowColTo(RowColumnClass &inRowCol)
{
  inRow += inRowCol.inRow;
  inCol += inRowCol.inCol;
}

//A public function to print the row and column of the object in the 
//format "[<row>,<col>]"
void RowColumnClass::printRowCol()
{
  cout << "[" << inRow << "," << inCol << "]";
}*/
