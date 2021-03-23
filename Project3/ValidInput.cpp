#include <iostream>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: October 21 2019
//Purpose: Develop a simple program to get an int from 
//input and check it

int main()
{
int a;
bool validInputFound;

cout << "Enter a: ";

validInputFound = false;
while (!validInputFound)
{
  cin >> a;
  if (cin.fail())
  {
    cin.clear();
    cin.ignore(200, '\n');
    cout << endl << "Fail state!" << endl;
    cout << "Try again - Enter a: ";
  }
  else
  {
    validInputFound = true;
  }
}

cout << "Entered: " << a << endl;

return 0;
}
