#include <iostream>
#include <fstream>

using namespace std;

#include "constants.h"
#include "ColorImageClass.h"

//Implementing functions of ColorImageClass:
//Default constructor that sets all pixels in the image to black
ColorImageClass::ColorImageClass()
{
  rowSize = 0;
  colSize = 0;
  arr = NULL;
}

//A public fuction to assign input color to all pixels in the image
void ColorImageClass::initializeTo(ColorClass &inColor)
{
  for (int i = 0; i < rowSize; i++)
    for (int j = 0; j < colSize; j++)  
      arr[i][j].setTo(inColor); 
}

//A public fuction to add corresponding pixels of the right hand side 
//to the current image and replace the resulted image in the 
//location of current image
bool ColorImageClass::addImageTo(ColorImageClass &rhsImg)
{
  bool retVal = false;

  for (int i = 0; i < rowSize; i++)
    for (int j = 0; j < colSize; j++)  
      if (arr[i][j].addColor(rhsImg.arr[i][j]))
        retVal = true;
           
  return retVal;
}

//A public fuction to add corresponding pixels of the specific number
//of input images and replace the resulted image in the location
//of current image
bool ColorImageClass::addImages(int numImgsToAdd, 
                                ColorImageClass imagesToAdd [])
{
  bool retVal = false;
  
  //Replace image number zero with current index image 
  for (int i = 0; i < rowSize; i++)
    for (int j = 0; j < colSize; j++)
      arr[i][j].setTo(imagesToAdd[0].arr[i][j]);

  for (int i = 1; i < numImgsToAdd; i++) 
    if (addImageTo(imagesToAdd[i]))
      retVal = true;
         
  return retVal;
}

//A public fuction to set the color of an specific pixel location 
bool ColorImageClass::setColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &inColor)
{
  bool retVal = true;

  int i = inRowCol.getRow();
  int j = inRowCol.getCol();

  if ((i >= 0) && (i < rowSize) && (j >= 0) && (j < colSize))
    arr[i][j].setTo(inColor);
  else 
    retVal = false; 

  return retVal;
}

//A public fuction to return the color of an specific pixel location  
bool ColorImageClass::getColorAtLocation(RowColumnClass &inRowCol,
                                         ColorClass &outColor)
{
  bool retVal = true;

  int i = inRowCol.getRow();
  int j = inRowCol.getCol();

  if ((i >= 0) && (i < rowSize) && (j >= 0) && (j < colSize))
    outColor.setTo(arr[i][j]);
  else 
    retVal = false; 

  return retVal;
}

//A public function to get and validate entered value from consol
bool ColorImageClass::validIntInput(int &inValConsl, int &mxInVal)
{
  bool validInputFound;

  validInputFound = false;
  while (!validInputFound)
  {
    cin >> inValConsl;
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(IGNORE_TO_CLEAN_VAL, '\n');
      cout << "Fail state!" << endl;
      cout << "Try again - Enter a number between " << MENU_START_VAL << " and " << mxInVal << " : ";
    }
    else
    {
      if ((inValConsl >= MENU_START_VAL) && (inValConsl <= mxInVal))
      {
        validInputFound = true;
      }
      else
      {
        cout << "Try again - Enter a number between " << MENU_START_VAL << " and " << mxInVal << " : ";    
      }    
    }
  }

  return !validInputFound;
}

//A public function to get and validate row and column size from a file 
bool ColorImageClass::getRowColumnInFile(int &outRowSize, int &outColSize, 
                                         ifstream &inFile)
{
  bool validInputFound = true;

  inFile >> outColSize;
  if (inFile.eof())
  {
    cout << "EOF before reading column-size" << endl;
    validInputFound = false;
  }
  else if (inFile.fail())
  {
    inFile.clear();
    inFile.ignore(IGNORE_TO_CLEAN_VAL, '\n');
    validInputFound = false;
  }

  inFile >> outRowSize;
  if (inFile.eof())
  {
    cout << "EOF before reading row-Size" << endl;
    validInputFound = false;
  }
  else if (inFile.fail())
  {
    inFile.clear();
    inFile.ignore(IGNORE_TO_CLEAN_VAL, '\n');
    validInputFound = false;
  }

  return validInputFound;
}

//A public function to check validation of input PPM file, and xtract
//row size, column size, and maximum color value
bool ColorImageClass::validFileInput(int &outRowSize, int &outColSize, 
                    int &outMaxColorVal, string fileNamePpm, ifstream &inFile)
{
  string ppmMagicNum;

  bool validInputFound = true;

  inFile.open(fileNamePpm.c_str());

  if (inFile.fail())
  {
    cout << "Unable to open input file!" << endl;
  }

  inFile >> ppmMagicNum;
  if (ppmMagicNum != PPM_MAGIC_STRING)
  {
    cout << "Error found when trying to read magic number - expected " 
         << PPM_MAGIC_STRING << " but found " << ppmMagicNum << endl;
    validInputFound = false;
  }
  if (inFile.eof())
  {
    cout << "EOF before reading PPM magic number" << endl;
    validInputFound = false;
  }
  else if (inFile.fail())
  {
    inFile.clear();
    inFile.ignore(IGNORE_TO_CLEAN_VAL, '\n');
    validInputFound = false;
  }

  validInputFound = getRowColumnInFile(outRowSize, outColSize, inFile);

  inFile >> outMaxColorVal;
  if (inFile.eof())
  {
    cout << "EOF before reading maximum color value" << endl;
    validInputFound = false;
  }
  else if (inFile.fail())
  {
    inFile.clear();
    inFile.ignore(IGNORE_TO_CLEAN_VAL, '\n');
    validInputFound = false;
  }

  return validInputFound;
}

//A public function to calculate and pass coordinates of upper left and lower
//right corners of a rectangle option that user entered
void ColorImageClass::rectSpecMtd(RowColumnClass &inRowColUpLeft, 
                                  RowColumnClass &inRowColLwrRight)
{
  int upLeftRecRow = inRowColUpLeft.getRow();
  int upLeftRecClmn = inRowColUpLeft.getCol();
  int lwrRightRecRow = inRowColLwrRight.getRow();
  int lwrRightRecClmn = inRowColLwrRight.getCol();  
  int rectSpecMtd, ctrRowRec, ctrClmnRec, numRowRec, numClmnRec, hlfNumRowRec,
      hlfNumClmnRec, recOptnCnt = 1;

  cout << recOptnCnt++ << 
          ". Specify upper left and lower right corners of rectangle" << endl;
  cout << recOptnCnt++ << 
          ". Specify upper left corner and dimensions of rectangle" << endl;
  cout << recOptnCnt++ << 
          ". Specify extent from center of rectangle" << endl;

  cout << "Enter int for rectangle specification method: "; 
  validIntInput(rectSpecMtd, recOptnCnt); 

  if (rectSpecMtd == 1)
  {
    cout << "Enter upper left corner row and column: ";
    cin >> upLeftRecRow;
    cin >> upLeftRecClmn; 
    cout << "Enter lower right corner row and column: ";
    cin >> lwrRightRecRow;
    cin >> lwrRightRecClmn; 
  }
  else if (rectSpecMtd == 2) 
  {
    cout << "Enter upper left corner row and column: ";
    cin >> upLeftRecRow;
    cin >> upLeftRecClmn; 
    cout << "Enter int for number of rows: ";
    cin >> numRowRec;
    cout << "Enter int for number of columns: ";
    cin >> numClmnRec;
    lwrRightRecRow = numRowRec + upLeftRecRow;
    lwrRightRecClmn = numClmnRec + upLeftRecClmn;
  }
  else if (rectSpecMtd == 3) 
  {
    cout << "Enter rectangle center row and column: ";
    cin >> ctrRowRec;
    cin >> ctrClmnRec;
    cout << "Enter int for half number of rows: ";
    cin >> hlfNumRowRec;
    cout << "Enter int for half number of columns: ";
    cin >> hlfNumClmnRec;

    upLeftRecRow = ctrRowRec - hlfNumRowRec;
    upLeftRecClmn = ctrClmnRec - hlfNumClmnRec;
    lwrRightRecRow = ctrRowRec + hlfNumRowRec;
    lwrRightRecClmn = ctrClmnRec + hlfNumClmnRec;
  }

  inRowColUpLeft.setRowCol(upLeftRecRow,upLeftRecClmn);
  inRowColLwrRight.setRowCol(lwrRightRecRow,lwrRightRecClmn);
}

//A public function to get color option from user and output set color
void ColorImageClass::colorChoice(int &mainMenuChoic, ColorClass &outColor)
{
  int colorChoiceInt, colorOptnCnt = 1;

  cout << colorOptnCnt++ << ". Red" << endl;
  cout << colorOptnCnt++ << ". Green" << endl;
  cout << colorOptnCnt++ << ". Blue" << endl;
  cout << colorOptnCnt++ << ". Black" << endl;
  cout << colorOptnCnt++ << ". White" << endl;
  
  if (mainMenuChoic == 1)
    cout << "Enter int for rectangle color: ";
  if (mainMenuChoic == 2)
    cout << "Enter int for pattern color: ";
  if (mainMenuChoic == 3)
    cout << "Enter int for transparecy color: ";

  validIntInput(colorChoiceInt, colorOptnCnt);

  if (colorChoiceInt == 1)
  {
    outColor.setToRed();
  }
  if (colorChoiceInt == 2)
  {
    outColor.setToGreen();
  }
  if (colorChoiceInt == 3)
  {
    outColor.setToBlue();
  }
  if (colorChoiceInt == 4)
  {
    outColor.setToBlack();
  }
  if (colorChoiceInt == 5)
  {
    outColor.setToWhite();
  }
}

//A public function to get fill option from user for rectangle, 
//and fill rectangle based on entered option.
void ColorImageClass::recFillOption(RowColumnClass &inRowColUpLeft, 
                    RowColumnClass &inRowColLwrRight, ColorClass &inColor)  
{
  int recFillOptn, recFillOptnCnt = 1;
  int upLeftRecRow = inRowColUpLeft.getRow();
  int upLeftRecClmn = inRowColUpLeft.getCol();
  int lwrRightRecRow = inRowColLwrRight.getRow();
  int lwrRightRecClmn = inRowColLwrRight.getCol();

  cout << recFillOptnCnt++ << ". No" << endl;
  cout << recFillOptnCnt++ << ". Yes" << endl;

  cout << "Enter int for rectangle fill option: ";
  validIntInput(recFillOptn, recFillOptnCnt);

  if (recFillOptn == 1)
  {
    for (int i = upLeftRecRow; i < lwrRightRecRow + 1; i++)
    {
      if ((i == upLeftRecRow) || ((i == lwrRightRecRow)))
      {
        for (int j = upLeftRecClmn; j < lwrRightRecClmn + 1; j++)  
        {
          inRowColUpLeft.setRowCol(i,j);
          setColorAtLocation(inRowColUpLeft,inColor);
        }
      }
      else
      {
        inRowColUpLeft.setRowCol(i,upLeftRecClmn);
        setColorAtLocation(inRowColUpLeft,inColor);
        inRowColLwrRight.setRowCol(i,lwrRightRecClmn);
        setColorAtLocation(inRowColLwrRight,inColor);
      }
    }
  }

  if (recFillOptn == 2)
  {
    for (int i = upLeftRecRow; i < lwrRightRecRow + 1; i++)
    {
      for (int j = upLeftRecClmn; j < lwrRightRecClmn + 1; j++)  
      {
        inRowColUpLeft.setRowCol(i,j);
        setColorAtLocation(inRowColUpLeft,inColor);
      }
    }
  }
}

//A public function to get and check main PPM file, and extract
//row size, column size, and maximum color value. It also generates 
// adynamic array to put all pixels from file into the array.
void ColorImageClass::getChkPpmFile(int &mxValColor, string fileNamePpm)
{
  ifstream inFile;

  validFileInput(rowSize, colSize, mxValColor, fileNamePpm, inFile);

  arr = new ColorClass*[rowSize];

  for (int i = 0; i < rowSize; i++)
  {
    arr[i] = new ColorClass[colSize];
  }

  for (int i = 0; i < rowSize; i++)
  {
    for (int j = 0; j < colSize; j++)
    {
      arr[i][j].readFrmFile(inFile);
    }
  }

  inFile.close();
}

//A public function to get and check a pattern txt file, and extract
//row size, column size, and all pixels to put on main PM file.
bool ColorImageClass::getChkTxtFile(RowColumnClass &inRowColUpLeft, 
                           ColorClass &inColor, string fileNameContPtrn)
{
  int upLeftRecRow = inRowColUpLeft.getRow();
  int upLeftRecClmn = inRowColUpLeft.getCol();
  int rowSizePtrn, colSizePtrn, tempInFile;
  ifstream inFile;
  bool validInputFound = true;

  inFile.open(fileNameContPtrn.c_str());

  if (inFile.fail())
  {
    cout << "Unable to open input file!" << endl;
  }

  validInputFound = getRowColumnInFile(rowSizePtrn, colSizePtrn, inFile);

  for (int i = 0; i < rowSizePtrn; i++)
  {
    for (int j = 0; j < colSizePtrn; j++)  
    {
      inFile >> tempInFile;
      if (tempInFile == 1)
      {
        arr[upLeftRecRow+i][upLeftRecClmn+j].setTo(inColor);
      }
    }
  }

  return validInputFound;
}

//A public function to get and check inserted PPM file on top of main PPM 
//file, and extract row size, column size, and maximum color value. It also 
//generates adynamic array to put all pixels from file into the array.
void ColorImageClass::getChkPpmInsrt(RowColumnClass &inRowColUpLeft, 
                               ColorClass &inColor, string fileNamePpmInsrt)
{
  int upLeftRecRow = inRowColUpLeft.getRow();
  int upLeftRecClmn = inRowColUpLeft.getCol();
  int rowSizeInsrt, colSizeInsrt, mxValColorInsrt;
  ifstream inFile;

  validFileInput(rowSizeInsrt, colSizeInsrt, mxValColorInsrt, 
                                    fileNamePpmInsrt, inFile);

  arrInsrt = new ColorClass*[rowSizeInsrt];

  for (int i = 0; i < rowSizeInsrt; i++)
  {
    arrInsrt[i] = new ColorClass[colSizeInsrt];
  }

  for (int i = 0; i < rowSizeInsrt; i++)
  {
    for (int j = 0; j < colSizeInsrt; j++)
    {
      arrInsrt[i][j].readFrmFile(inFile);
      if (!(arrInsrt[i][j].compareColor(inColor)))
      {
        arr[upLeftRecRow+i][upLeftRecClmn+j].setTo(arrInsrt[i][j]);
      }
    }
  }

  for (int i = 0; i < rowSizeInsrt; i++)
  {
    delete [] arrInsrt[i];
  }

  delete [] arrInsrt;

  inFile.close();
}

//A public fuction to write all pixels in the image into a file  
void ColorImageClass::printImage(ofstream &outFile)
{
  for (int i = 0; i < rowSize; i++)  
  {
    for (int j = 0; j < colSize; j++)  
    {
      arr[i][j].printComponentValues(outFile);
    }
    outFile << endl;
  }
}

//A public fuction to write magic number, row, colmn, max 
//color, and all pixels into a file and make a PPM image file
void ColorImageClass::writeOutPpmFile(int &mxValColor, string fileNamePpm)
{
  ofstream outFile;

  outFile.open(fileNamePpm.c_str());

  if (outFile.fail())
  {
    cout << "Unable to open output file" << endl;
  }

  outFile << PPM_MAGIC_STRING << endl;
  outFile << colSize << " " << rowSize << endl;
  outFile << mxValColor << endl;

  printImage(outFile);

  outFile.close();
}

//Destructor of the class where also delete main dynamic array
ColorImageClass::~ColorImageClass()
{
  for (int i = 0; i < rowSize; i++)
  {
    delete [] arr[i];
  }

  delete [] arr;
}
