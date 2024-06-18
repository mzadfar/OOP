#include <iostream>
#include <cmath>

using namespace std;

/*Programmer: A. H.
Purpose: Implement simple functionality to accrue total and monthly 
interest for an investment account*/

//define constants
const int FIRST_BALANCE_LIMIT = 1000;
const int SECOND_BALANCE_LIMIT = 15000;
const double FIRST_INTEREST_RATE = 0.15;
const double SECOND_INTEREST_RATE = 0.225;
const double THIRD_INTEREST_RATE = 0.4;
const double PERCENT_MULTIPLICATION = 0.01;
const int LOWER_LIMIT_MONTH = 0;
const double LOWER_LIMIT_BALANCE = 0;

//define 1st function: check user input values and execute 2nd function
bool accrueInterest(
double &balanceAmt,
const int numMonths,
const bool doPrintEachMonth
);

//define 2nd function: calculate monthly and total accrued interest
bool accrueOneMonthsInterest(
double &balanceAmt,
const bool doPrintInfo
);

//main program
#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
  //define variables
  double balanceAmt;
  double numMonths;
  bool doPrintEachMonth = false;
  char doPrintEachMonthYN;  //a variable to ask for printing info

  cout << "Enter the initial balance of the account: ";
  cin >> balanceAmt;
  cout << "Enter the number of months to accrue interest: ";
  cin >> numMonths;
  cout << "Show month-by-month results - 'y' for yes, any other for no: ";
  cin >> doPrintEachMonthYN;

  //convert 'y' for yes, any other for no to a boolean value
  if (doPrintEachMonthYN == 'y') 
    doPrintEachMonth = true; 

  //execute 1st function: check user input values and execute 2nd function
  accrueInterest(balanceAmt, numMonths, doPrintEachMonth);
  
  return 0;
}
#endif

//implement 1st function: check user input values and execute 2nd function
bool accrueInterest(
double &balanceAmt,
const int numMonths,
const bool doPrintEachMonth
)
{
  //define variables
  int i;
  double initbalanceAmt;

  initbalanceAmt = balanceAmt; //save current balance in a temporary variable

  if (balanceAmt < 0) //to check user put correct balance value
  {
    cout << "ERROR in accrueOneMonthsInterest: balanceAmt must be >= " 
    << LOWER_LIMIT_BALANCE << ", but the value " << balanceAmt << 
    " was provided!" << endl;
    cout << "Sorry, an error was detected.  Unable to provide results!"
    << endl;
  }
  else if (numMonths <= 0) //to check user put correct month value
  {
    cout << "ERROR in accrueInterest: numMonths must be > " 
    << LOWER_LIMIT_MONTH << ", but the value " <<  numMonths 
    << " was provided!" << endl;
    cout << "Sorry, an error was detected.  Unable to provide results!" 
    << endl;
  }
  else 
  {
    //amount values for balance and month are correct, 
    //run 2nd function to accrue monthly and total interests
    for(i = 0; i < numMonths; i++)
      accrueOneMonthsInterest(balanceAmt, doPrintEachMonth); 

    //total accrued interest and balance are printed
    cout << "Accruing interest for " << numMonths << " months! " << endl;
    cout << endl;
    cout << "Initial balance: " << initbalanceAmt << endl;  
    cout << "Total interest accrued: " << (balanceAmt - initbalanceAmt)
    << endl;
    cout << "Final balance: " << balanceAmt << endl;
  }

  return 0;
}

//implement 2nd function: monthly and total accrued interests
bool accrueOneMonthsInterest(
double &balanceAmt,
const bool doPrintInfo
)
{
  //define variables
  static int monthCount = 1;
  double interestRate;
  double interestAccrued;
  double totalInterestAccrued = 0;
  double initbalanceAmt;

  initbalanceAmt = balanceAmt; //save current balance in a temporary variable

  //check the interest rate corresponding to available balance
  if (balanceAmt < FIRST_BALANCE_LIMIT )
    interestRate = FIRST_INTEREST_RATE;
  //RESUBMISSION CODE UPDATE
  //1st mistake: I put or(||) instead of and(&&) in bellow statement
  else if (balanceAmt >= FIRST_BALANCE_LIMIT 
  && balanceAmt < SECOND_BALANCE_LIMIT)
    interestRate = SECOND_INTEREST_RATE;
  else 
    interestRate = THIRD_INTEREST_RATE;

  //convert interest value from percent to real value
  interestRate *= PERCENT_MULTIPLICATION;

  interestAccrued = balanceAmt*interestRate; //monthly accrued interest 
  totalInterestAccrued += interestAccrued; //total accrued interest
  balanceAmt += interestAccrued; //total available balance  

  if (doPrintInfo == true) //monthly accrued interest and balance are printed
  {
    cout << "Accruing interest for " << monthCount++ << " month: "
    << endl;
    cout << "  Initial balance: " << initbalanceAmt << endl;
    cout << "  Initial rate: " << interestRate << endl;  
    //RESUBMISSION CODE UPDATE
    //2nd mistake: I put interestAccrued instead of totalInterestAccrued bellow
    cout << "  Interest accrued: " << totalInterestAccrued << endl; 
    cout << "  New balance: " << balanceAmt << endl;
  }

  return 0;
}
