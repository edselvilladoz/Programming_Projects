//Edsel Villadoz Assignment #1 Algorithm Lec 1003


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
  //Declarations

  //Input Variables
  double p; //principal amount borrowed
  double a; //annual interest rate
  int y; //length of loan term in years

  //Output variables
  // including: annual interest rate & principal amount borrowed (y,p) 
  int N; //total number of payments
  double m; //monthly payment
  double r; //monthly interest rate
  double T; //total to be paid during the life of the loan
  double I; //total interest to be paid over the life of the loan

  //User input requests
  cout << endl << "Please enter the amount borrowed" << endl;
  cin >> p;
  cout << endl;

  cout << "Please enter the annual interest rate" << endl;
  cin >> a;
  cout << endl;

  cout << "Please enter the length of the loan (in years)" << endl;
  cin >> y;
  cout << endl;

  //Equations
  N = y * 12;
  r = (a / 12) / 100;
  
  m = (p * r * pow(1+r,N)) / (pow(1+r,N) - 1);

  T = m * N;
  I = T - p;

  //Output displays
  cout << setfill('*') << setw(40) << "*" << endl;
  cout << "Loan Summary Prepared For" << endl;
  cout << setfill('*') << setw(25) << left << "Edsel Villadoz" << setfill(' ') << setw(15) << right << "Assignment #1" << endl;
  cout << setfill('*') << left << setw(40) << "*" << endl;

  cout << setfill(' ') << setw(25) << "Annual Interest Rate " << setw(15) << right << fixed << setprecision(3) << a << "%" << endl;
  cout << setw(25) << left << "Monthly Interest Rate" << setw(15) << right << r << "%" << endl;
  cout << setw(25) << left << "Total Number of Payments" << setw(15) << right << N << endl << endl;

  cout << setw(20) << left << "Loan Amount" << right << setw(9) << "$ " << fixed << setprecision(2) << setw(11) << p  << "%" << endl;
  cout << setw(20) << left << "Monthly Payment" << right << setw(9) << "$ " << setw(11) << m << "%" << endl;
  cout << setw(20) << left << "Total to be Paid" << right << setw(9) << "$ " << setw(11) << T << "%" << endl;
  cout << setw(20) << left << "Total interest Paid" << right << setw(9) << "$ " << setw(11) << I << "%" << endl;
  cout << setfill('*') << left << setw(40) << "*" << endl;
 //test comment 
 return 0;
}
