// Edsel Villadoz Lec 1003 Assign #2

//This program is designed to read input from a data file to display a day's worth of pruchases made at a small store. This program will show the date the purchases were made along with the Receipt Number, Item ID number, Original Price, Percent Off, Sale Price, Quantity of Item Purchased, Total Cost of Items, Sales Tax per Item's Total Cost, Subtotal of All Items, Sales Tax of All Items and the Total Due.

#include <iostream>
#include <iomanip>

using namespace std;


int main ()
{
  int itemnum; // Specific Item ID Num
  double price; // Original Price of Item
  double saleprice; //Price of Item after discount
  int discount; //Percent to take off item original price
  int qty; //Amount of item purchased
  int year; //Year of purchase
  int month; //Month of purchase
  int day; //Day of purchase
  int receiptnum; //Receipt number of purchase set
  char ch,T,N; //reads and compares character inputs
  double tax; //tax of specific item
  double totalcost = 0; //Used to calculate total cost
  double totaltax= 0; //Used to calculate total sales tax
  double subtotal = 0;//Used to calculate Sub Total
  double totaldue = 0; // Used to calculate total due
  double daytotal = 0; //Used to calculate day sales total
  double daytaxtotal = 0; //Used to calculate day tax total

cout << endl;
 cout << "Edsel Villadoz, Assignment #2" << endl << endl; // Prints name and assignment #

cin >> year; // Read for Year
cin >> day; // Read for Day
cin >> month; // Read for Month

 cout << "Date of purchases: " << day << "/" << month << "/" << year << endl; //Prints date of purchase


cin >> receiptnum; // Read for Receipt Number


while (cin) // First While Loop

   {

     cout << "Receipt #" << receiptnum << endl;
     cout << setw(4) << "ITEM" << right << setw(11) << "ORIGINAL" << setw(5) << "PCT" << setw(15) << "SALES" << setw(20) << "TOTAL" << setw(10) << "SALES" << endl; //Prints receipt number and column titles

     cout << left << setw(4) << "ID#" << right << setw(11) << "PRICE" << setw(5) << "OFF" << setw(15) << "PRICE" << setw(5) << "QTY" << setw(15) << "COST" << setw(10) << "TAX" << endl; //Prints column titles

     cout << setfill ('-') << setw(65) << "-" << endl; // Fills spaces with "-"
   
     cin >> itemnum; // Read for Item ID Number

     while (itemnum != 0) // Second While Loop (Nested)

       {

	 cin >> price; //Read for Item Original Price
	 cin >> discount; //Read for percentage to be discounted
	 cin >> qty; //Read for quantity of item bought
	 cin >> ch; //read for N or T (N apply no tax / T appl tax) - Tax rate is 0.05

	 if (discount != 0) // Calculates for discount price if applicable
	   saleprice = price - (price * (double(discount)/100));
	 else
	   saleprice = price;

	 if (ch == 'T') // Calculates for tax if applicable
	   tax = 0.05 * (double (saleprice) * qty);
	 else
	   tax = 0.0;

	 totalcost = saleprice * qty; // Calculates Total Cost

	 cout << setfill(' ') << left << setw(5) << itemnum << right << setw(1) << "$" << fixed << setprecision(2) << setw(9) << price << setw(4) << discount << setw(1) << "%" << setw(5) << "$" << setw(10) << saleprice << setw(5) << qty << setw(5) << "$" << setw(10) << totalcost << setw(4) << "$" << setw(6) << tax << endl; //Prints item data

	 subtotal = subtotal + totalcost; // Calculates subtotal
	 totaltax = totaltax + tax; // Calculates totaltax
	 totaldue = subtotal + totaltax; // Calculates totaldue

	 daytotal = daytotal + totalcost; //Used to calculate day total
	 daytaxtotal = daytaxtotal + tax; // Used to calculate Day Sales Tax total

	 cin >> itemnum; // Reads integer number in file

       } // End of Nested While Loop
      
     cout << left << setw(36) << "SUBTOTAL" << right << setw(9) << "$" << setw(10) << subtotal << endl; //Prints Subtotal
     cout << left << setw(36) << "SALES TAX" << right << setw(9) << "$" << setw(10) << totaltax << endl; //Prints Sales tax
     cout << left << setw(36) << "TOTAL DUE" << right << setw(9) << "$" << setw(10) << totaldue  << endl << endl; //Prints Total Due

    subtotal = 0; //Resets subtotal to 0 for next purchase set
    totaltax = 0; //Resets totaltax to 0 for next purchase set
    totaldue = 0; //Resets totaldue to 0 for next purchase set

    cin >> receiptnum; //Reads next datatype in file

   } //End of First While Loop

 cout << endl; // Prints sales and tax totals for the date of purchase
 cout << "Total sales for " << day << "/" << month << "/" << year << " were " << daytotal << endl;
 cout << "Total sales tax collected for " << day << "/" << month << "/" << year << " was " << daytaxtotal << endl << endl;

return 0;
}
