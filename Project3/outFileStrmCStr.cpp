#include <iostream>
#include <fstream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: November 2 2019
//Purpose: Develop a simple program to open a file and read 
//int from it

int main()
{
string fileName;
ifstream inFile;
int intVal;

fileName = "thisIsMyFile.txt";
//inFile.open(fileName);
inFile.open(fileName.c_str());
inFile >> intVal;
cout << "I found the int: " << intVal << endl;
return 0;
}








