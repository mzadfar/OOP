#ifndef _ROWCOLUMNCLASS_H_
#define _ROWCOLUMNCLASS_H_
#include <iostream>

//Introducing RowColumnClass
class RowColumnClass{
private: 
  int inRow;
  int inCol;

public:
  RowColumnClass();
  RowColumnClass(int inRow, int inCol);

  void setRowCol(int inRow, int inCol);
  void setRow(int inRow);
  void setCol(int inCol);

  int getRow(); 
  int getCol();

  void addRowColTo(RowColumnClass &inRowCol);

  void printRowCol();
};

#endif
