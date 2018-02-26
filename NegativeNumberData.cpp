//Edsel Villadoz Lec 1003 Assignment 4

//This program is designed to promt the user for an input file of integers. The data from the input file will be read. The number of negative numbers in the file will be counted and the sum and average will be calculated. Numbers equal to or greater than 0  will be sorted from smallest to largest and will be printed. The average of the numbers that are equal to or greater than 0 will be calculated along with the variance and standard deviation. Of the numbers greater than or equal to 0, those that are prime numbers will be seperated from nonprime numbers and printed following sorting. Nonpriome numbers will be printed along with their number of factors.

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 30;//assumption that total numbers in file that are greater than or equal to 0 will be a max of 30

void arrange(int[], int);//void function to sort numbers form smallest to largest
void neg_num_data(int[], int, int&, int&, double&, ofstream&);//void function that will calculate and print negative number data
void pos_num_data(int[], int, double&, double&, double&, ofstream&);//void function that will calculate and print positive number data
void prime_num(int[], int, int&, ofstream&);//void function that will print prime numbers
void non_prime_num(int[], int, int&, ofstream&);//void function that will print nonprime numbers

int main()
{
  ifstream infile;//inputfile variable
  ofstream outfile;//outfile variable
  string infilename, outfilename;//string variables for input and output file names
  int list[MAX];//array to store data read from file
  int n = 0;//size of array
  int neg_count = 0;//count of negative numbers
  int neg_sum = 0;//sum of negative numbers
  int factor_count;//count of factors
  double neg_average;//avergae of negative numbers
  double pos_average;//average of positive numbers
  double var;//used to calculate variance
  double s_d;//used to calculate standard deviation


  cout << "Please enter the name of the inputfile" << endl;//prompts user for input file
 cin >> infilename;// reads for input file name
cout << endl;

 infile.open(infilename.c_str());//opens input file to be read

 cout << "Please enter the name of the file you wish to save to" << endl;//prompts user for output file
 cin >> outfilename;//reads for or creates outputfile
cout << endl;

 outfile.open(outfilename.c_str());//opens outputfile

 if (!infile)//if input file does not exist program will go through this if statement
 cout << "Input file does not exist" << endl;

 else // data from input file will be read and stored into an array
 {
  infile >> list[n];

  while (infile)

   {
     n++;
     infile >> list[n];
   }

  infile.close();//close input file when all data is read

 }

 //following will be written into output file

 outfile << endl << "Edsel Villadoz     Assignment 4" << endl << endl;

 arrange(list, n);//calls void function to sort data

 neg_num_data(list, n, neg_count, neg_sum, neg_average, outfile);//calls void function to calculate negative number data

 outfile << "Positive #'s in File" << endl;//lists numbers greater than or equal to 0

 for (int i = 0; i < n; i++)
   if (list[i] >= 0)
     outfile << setw(10) << list[i] << endl;

 outfile << endl;

 pos_num_data(list, n, pos_average, var, s_d, outfile);//calls void function to calculate positive number data

 outfile << "Prime Numbers" << endl;
 prime_num(list, n, factor_count, outfile);//calls void function to seperate and list prime numbers from data
 outfile << endl;

 outfile << "Nonprime numbers and Factor Counts" << endl;
 non_prime_num(list, n, factor_count, outfile);//calls void function to seperate and list nonprime numbers from data
 outfile << endl;

 outfile.close();//closes output file

return 0;
}

void arrange(int list[], int n)//bubblesort function
{
 int temp;

 for (int i = 0; i <n-1; i++)
   for (int j = 0; j < n-(i+1); j++)
     if (list[j] > list[j+1])
       {
	 temp = list[j];
	 list[j] = list[j+1];
	 list[j+1] = temp;
       }

}

void neg_num_data(int list[], int n, int& neg_count, int& neg_sum, double& neg_average, ofstream& outfile)//function that calculates negative number data
{

  for (int i = 0; i < n; i++)
    if (list[i] < 0)
      {
	neg_count++;//counts negative numbers
	neg_sum = neg_sum + list[i];//calculates sum of all negative numbers found in data
      }

  neg_average = double(neg_sum)/neg_count;//calculates average of negative numbers found in data

  outfile << "Negative Number Data" << endl;//Prints column title of negative number data
 outfile << fixed << setprecision(5);
 outfile << setfill('=') << setw(22) << "=" << endl << setfill(' ');

 if(neg_count == 0)//if there are no negative numbers in the data, this if statement will be followed
   outfile << "No negative values found in the file." << endl << endl;

 else//if there are negative numbers, data will be printed
   {
     outfile << "Count: " << neg_count << endl;
     outfile << "Sum: " << neg_sum << endl;
     outfile << "Average: " << neg_average << endl << endl;
     
     outfile << "Numbers >= 0 Data" << endl;
     outfile << setfill('=') << setw(20) << "=" << endl << setfill(' ');
   }
}

void pos_num_data(int list[], int n, double& pos_average, double& var, double& s_d, ofstream& outfile)//function that calculates positive number data
{
  int pos_count = 0;//used to count total of positive numbers
  int pos_sum = 0;//used to calculate sum of positive numbers
  double var_data = 0;//used to calculate variance

  for (int i = 0; i < n; i++)
    if (list[i] >= 0)
     {
      pos_count++;
      pos_sum = pos_sum + list[i];
     }

  pos_average = double(pos_sum)/pos_count;//calculates average of positive numbers

  for (int i = 0; i < n; i++)
    if (list[i] >= 0)
      var_data = var_data + pow(list[i]-pos_average,2);//used for variance calculation

  var = var_data/double(pos_count-1);//calculates variance of positive numbers
  s_d = sqrt(var);//calculates standard deviation of positive numbers

  if (pos_count == 0)//if mo numbers >= 0 are in the file this if statement will run
    outfile << "There are no numbers greater than or equal to 0, found in file." << endl <<endl;

  else
    {
      outfile << "Average: " << fixed << setprecision(5) << pos_average << endl;//prionts positive number data
      outfile << "Variance: " << var << endl;
      outfile << "Standard Deviation: " << s_d << endl << endl;
    }


}

void prime_num(int list[], int n, int& factor_count, ofstream& outfile)//used to list prime numbers
{
  int primecount = 0;//counts number of prime numbers found in data

 for(int i = 0; i < n; i++)
  {
    factor_count = 1;//1 to include number itself
    if(list[i] > 0)
     {
      for(int j = 1; j < list[i]; j++)
       {
	if(list[i] % j == 0)
	 {
	   factor_count++;//counts factors of each element of array
	 }
       }
      if (factor_count == 2)//if factor count is 2 then number is prime
      {
	primecount++;//counts number of primes
	outfile << setw(10) << right << list[i] << endl;
      }
     }  
  }

 if (primecount == 0)//if there are no primes in the data, this if statement will run
      outfile << "No prime numbers found." << endl;

}

void non_prime_num(int list[], int n, int& factor_count, ofstream& outfile)//used to list non prime numbers and count their factors
{
  int nonprimecount = 0;//used to count nonprime numbers

 for(int i = 0; i < n; i++)
  {
    factor_count = 1;//1 so that number itself is counted as factor
    if(list[i] > 0)
     {
      for(int j = 1; j < list[i]; j++)
       {
	if(list[i] % j == 0)
	 {
	   factor_count++;//counts factors of each element of array
	 }
       }
      if (factor_count > 2 || factor_count == 1)//if number of factors is greater than 2 then number is nonprime (with the exception of 1)
      {
      nonprimecount++;
      outfile << setw(10) << list[i] << setw(10) << factor_count << endl;
      }
     }   
  }

 if (nonprimecount == 0)//if no nonprimes are counted then this if statement will run
   outfile << "No nonprime numbers found." << endl;

}
