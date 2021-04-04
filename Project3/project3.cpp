#include <iostream>
#include <fstream>

using namespace std;

#include "ColorImageClass.h"

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: develop a program to modifying pictureson acomputer

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
  string fileNamePpm, fileNameContPtrn, fileNamePpmInsrt, fileNamePpmOut;
  int mainMenuCount, mainMenuChoic, upLeftRecRow, upLeftRecClmn, mxValColor;

  cout << "Enter string for PPM image file name to load: ";
  cin >> fileNamePpm;

  ColorImageClass ppmImage;
  ppmImage.getChkPpmFile(mxValColor, fileNamePpm);
  RowColumnClass rowColImageUpLeft;
  RowColumnClass rowColImageLwrLeft;
  ColorClass colorImage;  
  colorImage.setMaxColor(mxValColor);

  do
  {
    mainMenuCount = 0;

    cout << ++mainMenuCount << ". Annotate image with rectangle" << endl;
    cout << ++mainMenuCount << ". Annotate image with pattern from file" << endl;
    cout << ++mainMenuCount << ". Insert another imag" << endl;
    cout << ++mainMenuCount << ". Write out current image" << endl;
    cout << ++mainMenuCount << ". Exit the program" << endl;

    cout << "Enter int for main menu choice: ";
    ppmImage.validIntInput(mainMenuChoic, mainMenuCount); 

    if (mainMenuChoic == 1)
    {
      ppmImage.rectSpecMtd(rowColImageUpLeft, rowColImageLwrLeft);
      
      ppmImage.colorChoice(mainMenuChoic, colorImage);

      ppmImage.recFillOption(rowColImageUpLeft, rowColImageLwrLeft, colorImage);

    }
    else if (mainMenuChoic == 2)
    {
      cout << "Enter string for file name containing pattern: ";  
      cin >>  fileNameContPtrn;

      cout << "Enter upper left corner of pattern row and column: ";
      cin >> upLeftRecRow;
      cin >> upLeftRecClmn;  

      rowColImageUpLeft.setRowCol(upLeftRecRow, upLeftRecClmn);

      ppmImage.colorChoice(mainMenuChoic, colorImage);

      ppmImage.getChkTxtFile(rowColImageUpLeft, colorImage, fileNameContPtrn);
      
    }
    else if (mainMenuChoic == 3)
    {
      cout << "Enter string for file name of PPM image to insert: ";  
      cin >>  fileNamePpmInsrt;

      cout << "Enter upper left corner to insert image row and column: ";
      cin >> upLeftRecRow;
      cin >> upLeftRecClmn;

      rowColImageUpLeft.setRowCol(upLeftRecRow, upLeftRecClmn);

      ppmImage.colorChoice(mainMenuChoic, colorImage);

      ppmImage.getChkPpmInsrt(rowColImageUpLeft, colorImage, fileNamePpmInsrt);

    }
    else if (mainMenuChoic == 4)
    {
      cout << "Enter string for PPM file name to output: ";
      cin >>  fileNamePpmOut;

      ppmImage.writeOutPpmFile(mxValColor, fileNamePpmOut);
    }
  }
  while (mainMenuChoic != 5);

  cout << "Thank you for using this program" << endl;

  return 0;
}
#endif
