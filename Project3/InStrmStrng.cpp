#include <iostream>
#include <sstream>
#include <string>
#include <string>

using namespace std;

//Programmer: Amin Hasanzadeh
//Date: October 24 2019
//Purpose: develop a simple program to solve a 
//first order equation; Example: x = 54.75 + 3.1

void printFormat()
{
cout << "ERROR in format: " <<
"<var> = <lhs> <oper> <rhs>" << endl;
cout << "Example: x = 54.75 + 3.1" << endl;
cout << " Where <lhs> and <rhs> are doubles " <<
"and <oper> can be + -" << endl;
}
int main()
{
istringstream iss;
string lineStr;
string varStr;
string eqStr;
double lhsVal;
string operStr;
double rhsVal;
double resultVal;
bool success = false; //assume not initially

cout << "Enter an equation: ";
getline(cin, lineStr);

iss.str(lineStr);
iss >> varStr >> eqStr >> lhsVal >> operStr >> rhsVal;
//continued next column


if (iss.fail() || !iss.eof())
{
printFormat();
}
else
{
if (operStr == "+")
{
resultVal = lhsVal + rhsVal;
success = true;
}
else if (operStr == "-")
{
resultVal = lhsVal - rhsVal;
success = true;
}
else //invalid operator!
{
printFormat();
}
}

if (success)
{
cout << "Result: " << varStr <<
" = " << resultVal << endl;
}

return 0;
}
