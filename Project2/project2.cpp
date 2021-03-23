#include <iostream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: October 5 2019
//Purpose: develop three simple classes to represent and
//utilize colors and images

int const MIN_ALLOWED_COLOR_VAL = 0;
int const MAX_ALLOWED_COLOR_VAL = 1000;
int const ROW_INITIAL_VAL = -99999;
int const COL_INITIAL_VAL = -99999;
int const ROW_SIZE_VAL = 10;
int const COL_SIZE_VAL = 18;
const double BRIGHTNESS_FACTOR1 = 0.50;
const double BRIGHTNESS_FACTOR2 = 0.25;
const double BRIGHTNESS_FACTOR3 = 0.75;
const int ROW_TEST_VAL = 16;
const int COL_TEST_VAL = 32;
const int TEST_IMAGE_NUM = 3;

//Introducing ColorClass
class ColorClass{
private: 
  int inRed;
  int inGreen;
  int inBlue;
  
  //A function for clipping and evaluating input color parameters
  bool clipColorVal(int &inVal1, int &inVal2, int &inVal3);

public:
  ColorClass();
  ColorClass(int inRed, int inGreen, int inBlue);

  void setToBlack();
  void setToRed();
  void setToGreen();
  void setToBlue();
  void setToWhite();

  bool setTo(int inRed, int inGreen,int inBlue);

  bool setTo(ColorClass &inColor);

  bool addColor(ColorClass &rhs);

  bool subtractColor(ColorClass &rhs);

  bool adjustBrightness(double adjFactor);

  void printComponentValues();
};

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

//Introducing ColorImageClass
class ColorImageClass{
private: 
  static const int rowSize = ROW_SIZE_VAL;
  static const int colSize = COL_SIZE_VAL;
  ColorClass arr[rowSize][colSize];

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

  void printImage();
};

#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
  //Define 2 objects in ColorClass
  ColorClass testColor;
  ColorClass testColorOther(MAX_ALLOWED_COLOR_VAL, MAX_ALLOWED_COLOR_VAL,
                            MIN_ALLOWED_COLOR_VAL);
  //Define 2 objects in RowColumnClass
  RowColumnClass testRowCol;
  RowColumnClass testRowColOther(ROW_SIZE_VAL, COL_SIZE_VAL);
  
  //Define 2 objects in ColorImageClass
  ColorImageClass testImage;
  ColorImageClass testImages[3];

  //Test some basic ColorClass operations
  cout << "----------Test some basic ColorClass operations----------" << endl;
  cout << "Initial color of a pixel in 1st object: ";
  testColor.printComponentValues();
  cout << endl;

  cout << "Want yellow color in a pixel of 2nd object: ";
  testColorOther.printComponentValues();
  cout << endl;

  testColor.setToBlack();
  cout << "The color of a pixel of 1st object is set to black: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.setToRed();
  cout << "The color of a pixel of 1st object is set to red: ";
  testColor.printComponentValues();
  cout << endl;
  
  testColorOther.setToGreen();
  cout << "The color of a pixel in 1st object is set to green: ";
  testColorOther.printComponentValues();
  cout << endl;
  
  testColor.addColor(testColorOther);
  cout << "In 1st object, a green color pixel is added to a red one to make"
       << " yellow: ";
  testColor.printComponentValues();
  cout << endl;
  
  testColorOther.setToGreen();
  cout << "The color of pixel is set to green in 2nd object: ";
  testColorOther.printComponentValues();
  cout << endl;
  
  testColor.subtractColor(testColorOther);
  cout << "A green color pixel of 2nd object is subtracted from a yellow"
       << " one in 1st objet to make red: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.setTo(testColorOther);
  cout << "The color of a pixel in 1st object is set by the color of"
       << " another one: ";
  testColor.printComponentValues();
  cout << endl;
  
  testColor.setToBlue();
  cout << "The color of a pixel in 1st object is set to blue: ";
  testColor.printComponentValues();
  cout << endl;

  testColor.adjustBrightness(BRIGHTNESS_FACTOR1);
  cout << "The color of a pixel in 1st object is set to dimmer blue: ";
  testColor.printComponentValues();
  cout << endl;
  
  testColor.setToWhite();
  cout << "The color of a pixel in 1st object is set to white: ";
  testColor.printComponentValues();
  cout << endl;
  
  testColorOther.setTo(MAX_ALLOWED_COLOR_VAL, MAX_ALLOWED_COLOR_VAL, 
                       MIN_ALLOWED_COLOR_VAL);
  cout << "Want yellow color in a pixel of 2nd object: ";
  testColorOther.printComponentValues();
  cout << endl;

  //Test some basic RowColumnClass operations...
  cout << "----------Test some basic RowColClass operations----------"
       << endl;
  cout << "The initial values of row and column in 1st object: ";
  testRowCol.printRowCol();
  cout << endl;

  testRowCol.setRowCol(ROW_TEST_VAL, COL_TEST_VAL);
  cout << "Want set row to " << ROW_TEST_VAL << " and column to " 
       << COL_TEST_VAL << " in 1st object: ";
  testRowCol.printRowCol();
  cout << endl;

  cout << "Want set row to " << ROW_SIZE_VAL << " and column to "
       << COL_SIZE_VAL << " in 2nd object: ";
  testRowColOther.printRowCol();
  cout << endl;

  testRowCol.addRowColTo(testRowColOther);
  cout << "Want add row and column values in 2 objests, respectively, " <<
          "and put in 1st opject: ";
  testRowCol.printRowCol();
  cout << endl;

  testRowColOther.setRow(testRowCol.getRow());
  testRowColOther.setCol(testRowCol.getCol());
  cout << "Want to set row and column of 2nd object with return values" << 
          " of row and column from 1st object, respectively: ";
  testRowColOther.printRowCol();
  cout << endl;

  //Test some basic ColorImageClass operations...
  cout << "----------Test some operations of ColorImageClass----------"
       << endl;
  testColor.setToRed();
  testImage.initializeTo(testColor);

  testRowCol.setRowCol(ROW_TEST_VAL, ((COL_TEST_VAL >> 3) + 1));
  cout << "Want color at [" << ROW_TEST_VAL << ", " << 
       ((COL_TEST_VAL >> 3) + 1) << "]: Invalid Index!" << endl;
  cout << "As expected color at ";
  testRowCol.printRowCol();
  cout << " is: ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;

  testRowCol.setRow((ROW_TEST_VAL >> 2));
  cout << "Want color at [" << (ROW_TEST_VAL >> 2) << ", " <<
       ((COL_TEST_VAL >> 3) + 1) << "]: R: 1000 G: 0 B: 0" << endl;
  cout << "As expected color at ";
  testRowCol.printRowCol();
  cout << " is: ";
  if (testImage.getColorAtLocation(testRowCol, testColor))
  {
    testColor.printComponentValues();
  }
  else
  {
    cout << "Invalid Index!";
  }
  cout << endl;

  //Set up an array of images of different colors
  //Set array of testImages[0] to dimmer red
  testColor.setToRed();
  testColor.adjustBrightness(BRIGHTNESS_FACTOR2);
  testImages[(TEST_IMAGE_NUM - 3)].initializeTo(testColor);

  //Set array of testImages[1] to dimmer blue
  testColor.setToBlue();
  testColor.adjustBrightness(BRIGHTNESS_FACTOR3);
  testImages[(TEST_IMAGE_NUM - 2)].initializeTo(testColor);

  //Set array of testImages[2] to green
  testColor.setToGreen();
  testImages[(TEST_IMAGE_NUM - 1)].initializeTo(testColor);

  //Modify a individual pixel [4, 2] to white
  testRowCol.setRowCol((ROW_TEST_VAL >> 2), (COL_TEST_VAL >> 4));
  testColor.setToWhite();
  testImages[(TEST_IMAGE_NUM - 2)].setColorAtLocation(testRowCol, testColor);

  //Modify a individual pixel [4, 2] to black
  testRowCol.setRowCol((ROW_TEST_VAL >> 3), (COL_TEST_VAL >> 3));
  testColor.setToBlack();
  testImages[(TEST_IMAGE_NUM - 1)].setColorAtLocation(testRowCol, testColor);

  //Add up all images in testImages array and assign result
  //to the testImage image
  testImage.addImages(TEST_IMAGE_NUM, testImages);

  //Check some certain retun color values of pixels in row 4
  cout << "Added values:" << endl;
  for (int colInd = 0; colInd < (COL_TEST_VAL >> 2); colInd += 2)
  {
    testRowCol.setRowCol((ROW_TEST_VAL >> 2), colInd);
    cout << "Color at row and column ";
    testRowCol.printRowCol();
    cout << " is: ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }
  
  //Check some certain retun color values of pixels in column 4
  for (int rowInd = 0; rowInd < (ROW_TEST_VAL >> 1); rowInd += 2)
  {
    testRowCol.setRowCol(rowInd, (COL_TEST_VAL >> 3));
    cout << "Color at row and column ";
    testRowCol.printRowCol();
    cout << " is: ";
    if (testImage.getColorAtLocation(testRowCol, testColor))
    {
      testColor.printComponentValues();
    }
    else
    {
      cout << "Invalid Index!";
    }
    cout << endl;
  }
  
  cout << "Printing entire test image:" << endl;
  testImage.printImage();

  return 0;
}
#endif

//Implementing functions of ColorClass:
//A private function to clip the color values to an specific lower and upper
//limit values, and return a boolean (true) if any clipping was necessary  
bool ColorClass::clipColorVal(int &inVal1, int &inVal2, int &inVal3)
{
  bool retVal = ((inVal1 < MIN_ALLOWED_COLOR_VAL)
                || (inVal1 > MAX_ALLOWED_COLOR_VAL)
                || (inVal2 < MIN_ALLOWED_COLOR_VAL)
                || (inVal2 > MAX_ALLOWED_COLOR_VAL)
                || (inVal3 < MIN_ALLOWED_COLOR_VAL)
                || (inVal3 > MAX_ALLOWED_COLOR_VAL));

  if (inVal1 < MIN_ALLOWED_COLOR_VAL)
    inVal1 = MIN_ALLOWED_COLOR_VAL;

  if (inVal1 > MAX_ALLOWED_COLOR_VAL)
    inVal1 = MAX_ALLOWED_COLOR_VAL;

  if (inVal2 < MIN_ALLOWED_COLOR_VAL)
    inVal2 = MIN_ALLOWED_COLOR_VAL;

  if (inVal2 > MAX_ALLOWED_COLOR_VAL)
    inVal2 = MAX_ALLOWED_COLOR_VAL;

  if (inVal3 < MIN_ALLOWED_COLOR_VAL)
    inVal3 = MIN_ALLOWED_COLOR_VAL;

  if (inVal3 > MAX_ALLOWED_COLOR_VAL)
    inVal3 = MAX_ALLOWED_COLOR_VAL;

  return retVal;  
}

//Default constructor that set the color’s initial RGB values to the color
//full white
ColorClass::ColorClass()
{
  inRed = MAX_ALLOWED_COLOR_VAL;
  inGreen = MAX_ALLOWED_COLOR_VAL;
  inBlue = MAX_ALLOWED_COLOR_VAL;
}

//Default constructor that set the color’s initial RGB values to
//the values provided
ColorClass::ColorClass(int inRedNew, int inGreenNew, int inBlueNew)
{
  inRed = inRedNew;
  inGreen = inGreenNew;
  inBlue = inBlueNew;

  clipColorVal(inRed, inGreen, inBlue);
}

//A public function to set the color’s component color values to black
void ColorClass::setToBlack()
{
  inRed = MIN_ALLOWED_COLOR_VAL;
  inGreen = MIN_ALLOWED_COLOR_VAL;
  inBlue = MIN_ALLOWED_COLOR_VAL;
}

//A public function to set the color’s component color values to red
void ColorClass::setToRed()
{
  inRed = MAX_ALLOWED_COLOR_VAL;
  inGreen = MIN_ALLOWED_COLOR_VAL;
  inBlue = MIN_ALLOWED_COLOR_VAL;
}

//A public function to set the color’s component color values to green
void ColorClass::setToGreen()
{
  inRed = MIN_ALLOWED_COLOR_VAL;
  inGreen = MAX_ALLOWED_COLOR_VAL;
  inBlue = MIN_ALLOWED_COLOR_VAL;
}

//A public function to set the color’s component color values to blue
void ColorClass::setToBlue()
{
  inRed = MIN_ALLOWED_COLOR_VAL;
  inGreen = MIN_ALLOWED_COLOR_VAL;
  inBlue = MAX_ALLOWED_COLOR_VAL;
}

//A public function to set the color’s component color values to white
void ColorClass::setToWhite()
{
  inRed = MAX_ALLOWED_COLOR_VAL;
  inGreen = MAX_ALLOWED_COLOR_VAL;
  inBlue = MAX_ALLOWED_COLOR_VAL;
}

//A public function to set the color object's RGB values to the provided 
//values
bool ColorClass::setTo(int inRedNew, int inGreenNew,int inBlueNew)
{
  inRed = inRedNew;
  inGreen = inGreenNew;
  inBlue = inBlueNew;
  
  return clipColorVal(inRed, inGreen, inBlue);
}

//A public function to set the color object's RGB values to the passed 
//input parameter
bool ColorClass::setTo(ColorClass &inColor)
{
  inRed = inColor.inRed;
  inGreen = inColor.inGreen;
  inBlue = inColor.inBlue;

  return clipColorVal(inRed, inGreen, inBlue);
}

//A public function to add each RGB value to the corresponding value from
//the input parameter
bool ColorClass::addColor(ColorClass &rhs)
{
  inRed += rhs.inRed;
  inGreen += rhs.inGreen;
  inBlue += rhs.inBlue;

  return clipColorVal(inRed, inGreen, inBlue);
}

//A public function to subtract each RGB value to the corresponding value
//from the input parameter
bool ColorClass::subtractColor(ColorClass &rhs)
{
  inRed -= rhs.inRed;
  inGreen -= rhs.inGreen;
  inBlue -= rhs.inBlue;

  return clipColorVal(inRed, inGreen, inBlue);
}

//A public function to adjust brightness which multiplies each RGB value
//by the adjustment input parameter
bool ColorClass::adjustBrightness(double adjFactor)
{
  inRed = static_cast< int > (inRed * adjFactor);
  inGreen = static_cast< int > (inGreen * adjFactor);
  inBlue = static_cast< int > (inBlue * adjFactor);

  return clipColorVal(inRed, inGreen, inBlue);
}

//A public function to print the component color value with
//R:<red> G: <green> B:<blue> format
void ColorClass::printComponentValues()
{
  cout << "R: " << inRed << " G: " << inGreen << " B: " << inBlue;
}

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
}

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
}

//Implementing functions of ColorImageClass:
//Default constructor that sets all pixels in the image to black
ColorImageClass::ColorImageClass()
{
  for (int i = 0; i < rowSize; i++)
    for (int j = 0; j < colSize; j++)  
      arr[i][j].setToBlack();
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

//A public fuction to print all pixels in the image  
void ColorImageClass::printImage()
{
  for (int i = 0; i < rowSize; i++)  
    for (int j = 0; j < colSize; j++)  
    {
      arr[i][j].printComponentValues();
      if (j < (colSize - 1))
        cout << "--";
      if (j == (colSize - 1))
        cout << endl;
    }
}

