//EDSEL VILLADOZ CS 202 ASSIGNMENT 2

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>//formatted output to clean it up a bit
#include <string>
#include <cctype>

using namespace std;

const int MAX = 50;

struct automobile_data
{
  string make;
  string model;
  unsigned int year;
  string color;
  unsigned int msrp;
};

void fixinput (string&);
void lowsort (automobile_data[],int);
void highsort (automobile_data[],int);


int main(int args, char * argv[])
{
  ifstream infile;
  automobile_data automobile[MAX];
  int n = 0;
  string attribute;
  string detail;

  infile.open(argv[1]);

  if (!infile.is_open())
    {
      cout << "File not found!" << endl;
      exit(0);
    }

  else
    while (infile)//loop to store input file into an array of structs
      {
	n++;
	infile >> automobile[n].make;
	infile >> automobile[n].model;
	infile >> automobile[n].year;
	infile >> automobile[n].color;
	infile >> automobile[n].msrp;
      }

 
  cout << "Please enter search type or 'q' to quit: ";
  cin >> attribute;//reads in user input for search type

  fixinput(attribute);//calls function to format user's first input

  if (attribute == "Q")//if user types q or Q, program will DIE
   {
     cout << endl <<  "Adios, amigo." << endl << endl;
     return 0;
   }

  cin >> detail;//reads user input for second search type
  fixinput(detail);//calls function to format user's second input
  
  cout << endl << endl;

  while (cin)//loop to search for matching search criteria
      {
	if (attribute == "Make")
	  {
	    for (int i = 1; i < n; i++)
		  {
		    if (detail == automobile[i].make)//Prints out data that matches user input, repeats for all search types just change in which data to match
		    {
		      cout << setw(8) << left << "Make:  " << setw(10) << automobile[i].make << endl;
		      cout << setw(8) << left << "Model:  " << setw(10) << automobile[i].model << endl;
		      cout << setw(8) << left << "Year:  " << setw(10) << automobile[i].year << endl;
		      cout << setw(8) << left << "Color:  " << setw(10) << automobile[i].color << endl;
		      cout << setw(8) << left << "MSRP:  " << setw(10) << automobile[i].msrp << endl << endl << endl;
		    }
		  }
	  }

	else if (attribute == "Model")
	  {
	      for (int i = 1; i < n; i++)
		  {
		    if (detail == automobile[i].model)
		    {
		      cout << setw(8) << left << "Make:  " << setw(10) << automobile[i].make << endl;
		      cout << setw(8) << left << "Model:  " << setw(10) << automobile[i].model << endl;
		      cout << setw(8) << left << "Year:  " << setw(10) << automobile[i].year << endl;
		      cout << setw(8) << left << "Color:  " << setw(10) << automobile[i].color << endl;
		      cout << setw(8) << left << "MSRP:  " << setw(10) << automobile[i].msrp << endl << endl << endl;
		    }
		  }
	  }

	else if (attribute == "Year")
	  {
              unsigned int intyear = atoi(detail.c_str());//changes string into integer
	    
	      for (int i = 1; i < n; i++)
		  {
		    if (intyear == automobile[i].year)
		    {
		      cout << setw(8) << left << "Make:  " << setw(10) << automobile[i].make << endl;
		      cout << setw(8) << left << "Model:  " << setw(10) << automobile[i].model << endl;
		      cout << setw(8) << left << "Year:  " << setw(10) << automobile[i].year << endl;
		      cout << setw(8) << left << "Color:  " << setw(10) << automobile[i].color << endl;
		      cout << setw(8) << left << "MSRP:  " << setw(10) << automobile[i].msrp << endl << endl << endl;
		    }
		  }
	  }

	else if (attribute == "Color")
	  {
	      for (int i = 1; i < n; i++)
		  {
		    if (detail == automobile[i].color)
		    {
		      cout << setw(8) << left << "Make:  " << setw(10) << automobile[i].make << endl;
		      cout << setw(8) << left << "Model:  " << setw(10) << automobile[i].model << endl;
		      cout << setw(8) << left << "Year:  " << setw(10) << automobile[i].year << endl;
		      cout << setw(8) << left << "Color:  " << setw(10) << automobile[i].color << endl;
		      cout << setw(8) << left << "MSRP:  " << setw(10) << automobile[i].msrp << endl << endl << endl;
		    }
		  }
	  }

	else if(attribute == "List")
	  {
	    if (detail == "Low")
	      {
		lowsort(automobile, n);//calls void function for bubble sort low to high
		for (int i = 1; i < n; i++)//prints msrp from low to high
		  {
		      cout << setw(8) << left << "Make:  " << setw(10) << automobile[i].make << endl;
		      cout << setw(8) << left << "Model:  " << setw(10) << automobile[i].model << endl;
		      cout << setw(8) << left << "Year:  " << setw(10) << automobile[i].year << endl;
		      cout << setw(8) << left << "Color:  " << setw(10) << automobile[i].color << endl;
		      cout << setw(8) << left << "MSRP:  " << setw(10) << automobile[i].msrp << endl << endl << endl;
		  }	       
	      }

	    if (detail == "High")
	      {
		highsort(automobile, n);//calls void function for bubble sort high to low
		for (int i = 1; i < n-1; i++)//prints msrp from high to low
		  {
		      cout << setw(8) << left << "Make:  " << setw(10) << automobile[i].make << endl;
		      cout << setw(8) << left << "Model:  " << setw(10) << automobile[i].model << endl;
		      cout << setw(8) << left << "Year:  " << setw(10) << automobile[i].year << endl;
		      cout << setw(8) << left << "Color:  " << setw(10) << automobile[i].color << endl;
		      cout << setw(8) << left << "MSRP:  " << setw(10) << automobile[i].msrp << endl << endl << endl;
		  }
	      }
	  }
	      		
	else// repeats user prompts and functions to format user input
	cout << "Invalid search type. Please try again." << endl << endl << endl;

	cout << "Please enter search type or 'q' to quit: ";
	cin >> attribute;//same as before while loop
	fixinput(attribute);
	
        if (attribute == "Q")//if user types q or Q, program will DIE
	  {
	    cout << endl <<  "Adios, amigo." << endl << endl;
	    return 0;
	  }

	cin >> detail;//same as before while loop
	fixinput(detail);
  	
	cout << endl << endl;
  }

			
  //return 0;//usless return 0 because end of program will be determined by You-ser.
};

void fixinput (string& attribute)//sets first letter of string to capital letter, following letters will be lowercase
{
  int length = attribute.length();

  attribute[0] = toupper(attribute[0]);
  for (int i = 1; i < length; i++)
    attribute[i] = tolower(attribute[i]);
}

void lowsort (automobile_data automobile[], int n)//bubble sort low to high
{
  automobile_data temp;
  for (int i = 0; i < n-1; i++)
    for (int j = 0; j < n-(i+1); j++)
      if (automobile[j].msrp > automobile[j+1].msrp)
	{
	  temp = automobile[j];
	  automobile[j] = automobile[j+1];
	  automobile[j+1] = temp;
	}
}

void highsort (automobile_data automobile[], int n)//bubble sort high to low
{
  automobile_data temp;
  for (int i = 0; i < n-1; i++)
    for (int j = 0; j < n-(i+1); j++)
      if (automobile[j].msrp < automobile[j+1].msrp)
	{
	  temp = automobile[j];
	  automobile[j] = automobile[j+1];
	  automobile[j+1] = temp;
	}
}
