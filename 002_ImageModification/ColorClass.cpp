#include <iostream>
#include <fstream>

using namespace std;

#include "constants.h"
#include "ColorClass.h"

//Implementing functions of ColorClass:
//A private function to clip the color values to an specific lower and upper
//limit values, and return a boolean (true) if any clipping was necessary  
bool ColorClass::clipColorVal(int &inVal1, int &inVal2, int &inVal3, int &inMxValColorNew)
{
  bool retVal = ((inVal1 < MIN_ALLOWED_COLOR_VAL)
                || (inVal1 > inMxValColorNew)
                || (inVal2 < MIN_ALLOWED_COLOR_VAL)
                || (inVal2 > inMxValColorNew)
                || (inVal3 < MIN_ALLOWED_COLOR_VAL)
                || (inVal3 > inMxValColorNew));

  if (inVal1 < MIN_ALLOWED_COLOR_VAL)
  {
    inVal1 = MIN_ALLOWED_COLOR_VAL;
  }
  if (inVal1 > inMxValColorNew)
  {
    inVal1 = inMxValColorNew;
  }
  if (inVal2 < MIN_ALLOWED_COLOR_VAL)
  {
    inVal2 = MIN_ALLOWED_COLOR_VAL;
  }
  if (inVal2 > inMxValColorNew)
  {
    inVal2 = inMxValColorNew;
  }
  if (inVal3 < MIN_ALLOWED_COLOR_VAL)
  {
    inVal3 = MIN_ALLOWED_COLOR_VAL;
  }
  if (inVal3 > inMxValColorNew)
  {
    inVal3 = inMxValColorNew;
  }

  return retVal;  
}

//Default constructor that set the color’s initial RGB values to the color
//full white
ColorClass::ColorClass()
{
  inRed = MIN_ALLOWED_COLOR_VAL;
  inGreen = MIN_ALLOWED_COLOR_VAL;
  inBlue = MIN_ALLOWED_COLOR_VAL;
}

//Default constructor that set the color’s initial RGB values to
//the values provided
ColorClass::ColorClass(int inRedNew, int inGreenNew, int inBlueNew, int &inMxValColorNew)
{
  inRed = inRedNew;
  inGreen = inGreenNew;
  inBlue = inBlueNew;
  inMxValColor = inMxValColorNew;

  clipColorVal(inRed, inGreen, inBlue, inMxValColorNew);
}

//A public fuction to set the column value of the object
//to the input values
int ColorClass::getMaxColor()
{
  return inMxValColor;
}

//A public fuction to return the row value of the object
//to the caller
void ColorClass::setMaxColor(int inMxValColorNew) 
{ 
  inMxValColor = inMxValColorNew;  
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
  inRed = inMxValColor;
  inGreen = MIN_ALLOWED_COLOR_VAL;
  inBlue = MIN_ALLOWED_COLOR_VAL;
}

//A public function to set the color’s component color values to green
void ColorClass::setToGreen()
{
  inRed = MIN_ALLOWED_COLOR_VAL;
  inGreen = inMxValColor;
  inBlue = MIN_ALLOWED_COLOR_VAL;
}

//A public function to set the color’s component color values to blue
void ColorClass::setToBlue()
{
  inRed = MIN_ALLOWED_COLOR_VAL;
  inGreen = MIN_ALLOWED_COLOR_VAL;
  inBlue = inMxValColor;
}

//A public function to set the color’s component color values to white
void ColorClass::setToWhite()
{
  inRed = inMxValColor;
  inGreen = inMxValColor;
  inBlue = inMxValColor;
}

//A public function to set the color object's RGB values to the provided 
//values
bool ColorClass::setTo(int inRedNew, int inGreenNew,int inBlueNew)
{
  inRed = inRedNew;
  inGreen = inGreenNew;
  inBlue = inBlueNew;
  
  return clipColorVal(inRed, inGreen, inBlue, inMxValColor);
}

//A public function to set the color object's RGB values to the passed 
//input parameter
bool ColorClass::setTo(ColorClass &inColor)
{
  inRed = inColor.inRed;
  inGreen = inColor.inGreen;
  inBlue = inColor.inBlue;

  return clipColorVal(inRed, inGreen, inBlue, inMxValColor);
}

//A public function to add each RGB value to the corresponding value from
//the input parameter
bool ColorClass::addColor(ColorClass &rhs)
{
  inRed += rhs.inRed;
  inGreen += rhs.inGreen;
  inBlue += rhs.inBlue;

  return clipColorVal(inRed, inGreen, inBlue, inMxValColor);
}

//A public function to subtract each RGB value to the corresponding value
//from the input parameter
bool ColorClass::subtractColor(ColorClass &rhs)
{
  inRed -= rhs.inRed;
  inGreen -= rhs.inGreen;
  inBlue -= rhs.inBlue;

  return clipColorVal(inRed, inGreen, inBlue, inMxValColor);
}

bool ColorClass::compareColor(ColorClass &rhs)
{
  return ((inRed == rhs.inRed) && (inGreen == rhs.inGreen) && (inBlue == rhs.inBlue));
}

//A public function to adjust brightness which multiplies each RGB value
//by the adjustment input parameter
bool ColorClass::adjustBrightness(double adjFactor)
{
  inRed = static_cast< int > (inRed * adjFactor);
  inGreen = static_cast< int > (inGreen * adjFactor);
  inBlue = static_cast< int > (inBlue * adjFactor);

  return clipColorVal(inRed, inGreen, inBlue, inMxValColor);
}

bool ColorClass::readFrmFile(ifstream &inFile)
{
  inFile >> inRed;
  inFile >> inGreen;
  inFile >> inBlue;

  return clipColorVal(inRed, inGreen, inBlue, inMxValColor);
}

//A public function to print the component color value with
//R:<red> G: <green> B:<blue> format
void ColorClass::printComponentValues(ofstream &outFile)
{
  outFile << inRed << " ";
  outFile << inGreen << " ";
  outFile << inBlue << " ";
}

