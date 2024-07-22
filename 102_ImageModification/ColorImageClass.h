#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_
#include <iostream>
#include <fstream>

#include "RowColumnClass.h"
#include "ColorClass.h"

//Introducing ColorImageClass
class ColorImageClass{
private: 
  int rowSize, colSize, mxValColor;
  ColorClass **arr;
  ColorClass **arrInsrt;

public:
  ColorImageClass();

  void initializeTo(ColorClass &inColor);

  bool addImageTo(ColorImageClass &rhsImg);

  bool addImages(int numImgsToAdd,
                 ColorImageClass imagesToAdd []);

  bool setColorAtLocation(RowColumnClass &inRowCol,
                          ColorClass &inColor);

  bool getColorAtLocation(RowColumnClass &inRowCol,
                          ColorClass &outColor);

  bool validIntInput(int &inValConsl, int &mxInVal);

  bool getRowColumnInFile(int &outRowSize, int &outColSize, ifstream &inFile);

  bool validFileInput(int &outRowSize, int &outColSize, int &outMaxColorVal, string fileNamePpm, ifstream &inFile);

  void rectSpecMtd(RowColumnClass &inRowColUpLeft, RowColumnClass &inRowColLwrRight);

  void colorChoice(int &mainMenuChoic, ColorClass &outColor);

  void recFillOption(RowColumnClass &inRowColUpLeft, RowColumnClass &inRowColLwrRight, ColorClass &inColor);

  void getChkPpmFile(int &mxValColor, string fileNamePpm);

  bool getChkTxtFile(RowColumnClass &inRowColUpLeft, ColorClass &inColor, string fileNameContPtrn);

  void getChkPpmInsrt(RowColumnClass &inRowColUpLeft, ColorClass &inColor, string fileNamePpmInsrt);

  void printImage(ofstream &outFile);

  void writeOutPpmFile(int &mxValColor, string fileNamePpm);

  ~ColorImageClass();
};

#endif
