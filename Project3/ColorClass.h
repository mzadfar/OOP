#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_
#include <iostream>
#include <fstream>
#include "constants.h"

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: develop program for header file of color class 
//to modifying pictures on a computer

//Introducing ColorClass
class ColorClass{
private: 
  int inRed;
  int inGreen;
  int inBlue;
  int inMxValColor = MAX_ALLOWED_COLOR_VAL;

  //A function for clipping and evaluating input color parameters
  bool clipColorVal(int &inVal1, int &inVal2, int &inVal3, int &inMxValColor);

public:
  ColorClass();
  ColorClass(int inRed, int inGreen, int inBlue, int &inMxValColorNew);

//  int getMaxColor();
  void setMaxColor(int inMxValColor);

  void setToBlack();
  void setToRed();
  void setToGreen();
  void setToBlue();
  void setToWhite();

//  bool setTo(int inRed, int inGreen,int inBlue);

  bool setTo(ColorClass &inColor);

/*  bool addColor(ColorClass &rhs);

  bool subtractColor(ColorClass &rhs);
  
  bool adjustBrightness(double adjFactor);
*/
  bool compareColor(ColorClass &rhs);

  bool readFrmFile(ifstream &inFile);

  void printComponentValues(ofstream &outFile);
};

#endif
