#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_
#include <iostream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: develop a program to define all constants used 
//in whole project to modifying pictures on a computer

int const MIN_ALLOWED_COLOR_VAL = 0;
int const MAX_ALLOWED_COLOR_VAL = 1000;
int const MENU_START_VAL = 1;
int const ROW_INITIAL_VAL = -99999;
int const COL_INITIAL_VAL = -99999;
string const PPM_MAGIC_STRING = "P3";
int const IGNORE_TO_CLEAN_VAL = 200;
int const ANNOTAT_IMAGE_W_RECT = 1;
int const ANNOTAT_IMAGE_W_PATRN = 2;
int const INSRT_ANOTHER_IMAGE = 3;
int const WRITEOUT_CURRNT_IMAGE = 4;
int const EXIT_PROGRAM = 5;
int const UP_LFT_LOW_RGHT_CRNR = 1;
int const UP_LFT_CRNR_ROW_COL_DIMEN = 2;
int const EXTENT_FRM_CNTR = 3;
int const RECT_COLOR = 1;
int const PATTRN_COLOR = 2;
int const TRANSPAR_COLOR = 3;
int const SET_TO_RED = 1;
int const SET_TO_GREEN = 2;
int const SET_TO_BLUE = 3;
int const SET_TO_BLACK = 4;
int const SET_TO_WHITE = 5;
int const RECT_NOT_FILL = 1;
int const RECT_DO_FILL = 2;

#endif
