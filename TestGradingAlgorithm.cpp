//Edsel Villadoz Assignment 5 Lec 1003 Lab 1011


/*This program is designed to grade and print the results of a test taken by a group of students. The program will prompt and read for a inputfile that will include an answer-key, student ID#, first and last name of the students and the students answers. The program will store the data into an array of structs.

The program will also do the following:
-format the student names so that the first letter of each name is capitalized and the following letters are lowercase
-use the key to grade the exam and store each student's score into the array
-interactively prompt for two input files and an output file
-print out my name and assignment #
-print out the name's of the students in alphebetical order along with their ID# and score
-will display class standing with ID# and test score from highest to lowest
     -standing report will also include:
          - number of students that participated in the test
          - class average
          - the median
-indicate the start of second input file processing
-write test key to output file
-search for integer read, if number matches with student ID then the following will be displayed:
     - student's name, test score, and test answers
-no integers match then a merror message will be displayed

*/


#include <iostream> //libraries used
#include <cctype>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAX = 50;//max for array

struct class_data
{
  int ID;
  string fname;
  string lname;
  string answers;
  int score;
};

void fix_fname (string&);
void fix_lname (string&);
void format (class_data[], int, ofstream&);
int calc_score (string&, string&);
void sort (class_data[], int);
void class_standing (class_data[], int, ofstream&);

int main()
{
  ifstream infile; //used to reference input file
  ofstream outfile; //used to reference output file
  string infilenameone, infilenametwo, outfilename; //name of input and output files
  class_data student[MAX]; // array of structs
  int n; //variable for number of students
  string answerkey; //stores answerkey
  int class_totalscore = 0;//used to compute class totalscore for average
  double average;//variable to compute average
  int targetID;//used to search student ID from second input file
  double median;//used to find median

  cout << "Please enter the name of the first input file" << endl;//prompts for input file
  cin >> infilenameone;
  cout << endl;

  infile.open(infilenameone.c_str());//opens input file

  cout << "Please enter the name of the file you would like to save to" << endl;//prompts for output file
  cin >> outfilename;
  cout << endl;

  outfile.open(outfilename.c_str());//opens output file

  cout << "Please enter the name of the second input file" << endl;//prompts for second input file
  cin >> infilenametwo;

  if (!infile)//will run if input file does not exist
    cout << "Input file cannot be opened." << endl;

  else //reads and stores data from first input file
    {
      infile >> answerkey;
      n = -1;
      while (infile)
	{
	  n++;

	  infile >> student[n].ID;

	  infile >> student[n].fname;
	  fix_fname(student[n].fname);//calls function to fix first name of student

	  infile >> student[n].lname;
	  fix_lname(student[n].lname);//calls function to fix last name of student

	  infile >> student[n].answers;
	  student[n].score = calc_score(answerkey, student[n].answers);// calls function to calculate and store student score

	  class_totalscore = class_totalscore + student[n].score;//used to calculate total score of students for average

	}
    
      infile.close();//closes first input file
    }

  outfile << "Edsel Villadoz     Assignment #5" << endl << endl;

  sort(student, n);//calls function to sort las names in alphabetical order
  format(student, n, outfile);//calls function to print student name, id number and score
  class_standing(student, n, outfile);//calls function to order student id# from highest score to lowest score

  average = double(class_totalscore)/n;//computes average score

  for (int i = 0; i < n; i++)//used to compute median score
    {
      if (n % 2 == 0)
	median = (student[n/2].score + student[(n/2)-1].score)/double(2);
      else
	median = student[n/2].score;
    }
  //prints number of students, class average and median
  outfile << "# of Students: " << n << endl;
  outfile << fixed << setprecision(2) << "Class Average: " << average << endl;
  outfile << "Median Score : " << median << endl << endl;

  //Begins Student Search File Processing

  outfile << "BEGIN STUDENT SEARCH FILE PROCESSING" << endl << endl;
  outfile << "Test key: " << answerkey << endl << endl;//prints test key

  infile.open(infilenametwo.c_str());//opens second input file

  if (!infile) //if sceond input file does not exist if statement will run
    cout << "Input file cannot be opened" << endl;


  else //reads and stores data from second input file
    {

      infile >> targetID; // stores integer into variable for search
      bool foundid = false;//used for search

      while (infile)
	{
	  
	  for (int i = 0; i < n; i++)
	    {
	      if (targetID == student[i].ID)//if integers match it will enter this if statement
		{ 
		  foundid = true;//if entered, bool will be true
		  outfile << "ID#: " << setw(5) << student[i].ID << endl;
		  outfile << "Name: " << student[i].fname << " " << student[i].lname << endl;
		  outfile << "Test score: " << student[i].score << endl;
		  outfile << "Test responses: " << student[i].answers << endl << endl;
		}
	    }
	  if (!foundid)//if no match is found this if statement will run
		outfile << targetID << " is not a valid stuednt ID#" << endl << endl;

	  foundid = false;//resets bool
	  infile >> targetID;//reads for next data
	}
    }

  infile.close();//closes second input file

  outfile.close();//closes output file


  return 0;

}

void fix_fname (string& fname)//function used to fix first name
{
  int nlength = fname.length();

  fname[0] = toupper(fname[0]);
  for (int i = 1; i < nlength; i++)
    fname[i] = tolower(fname[i]);
}

void fix_lname (string& lname)//function used to fix last name
{
  int llength = lname.length();

  lname[0] = toupper(lname[0]);
  for (int i = 1; i < llength; i++)
    lname[i] = tolower(lname[i]);
}

int calc_score (string& answerkey, string& answers)//function that returns totalscore of student
{ int maxscore = 0;
  int wrongcount = 0;
  int totalscore = 0;

  for (int i = 0; i < answerkey.length(); i++)
    maxscore = maxscore + 5;

  for (int i = 0; i < answers.length(); i++)
    answers[i] = tolower(answers[i]);

  for (int i = 0; i < answerkey.length(); i++)
   if (answers[i] != answerkey[i])
	wrongcount = wrongcount + 1;

  totalscore = maxscore - (wrongcount * 5);

  return totalscore;

}

void sort (class_data student[], int n)//function that sorts last name alphabetically
{
  class_data temp;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - (i + 1); j++)
      if (student[j].lname > student[j+1].lname)
	{
	  temp = student[j];
	  student[j] = student[j+1];
	  student[j+1] = temp;
	}
}


void format (class_data student[], int n, ofstream& outfile)//function that formats and prints student name, id, and score
{
  outfile << left << setw(20) << "NAME" << right << setw(5) << "ID#" << setw(10) << "SCORE" << endl;

  for (int i = 0; i < n; i++)
    {
      outfile << setw(20) << left  << student[i].lname + "," + student[i].fname << right << setw(5) << student[i].ID << setw(10) << student[i].score << endl; 
    }

  outfile << endl;

}

void class_standing(class_data student[], int n, ofstream& outfile)//prints and orders the score and ID# of the students
{
  
  class_data temp;
  for (int i = 0; i < n - 1; i++)
    for (int j = 0; j < n - (i + 1); j++)
      if (student[j].score < student[j+1].score)
	{
	  temp = student[j];
	  student[j] = student[j+1];
	  student[j+1] = temp;
	}
 
  outfile << "CLASS STANDINGS" << endl;
  outfile << left << setw(8) << "ID#" << setw(10) << "SCORE" << endl;

  for (int i = 0; i < n; i++)
    outfile << setw(3) << right << student[i].ID << setw(10) << student[i].score << endl;

  outfile << endl;

}


