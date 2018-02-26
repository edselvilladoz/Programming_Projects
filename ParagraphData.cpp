// This program is designed to read data from a file. This program will count and display the number of non-whitespaces, letters, vowels and digits found in the file. For every "word" that is read it will convert all letters into lowercase letters and will remove any leading and trailing non-letter/non-numeric characters. The program will also determine and display the longest word before and after formatting The average length of formatted words will be calculated and displayed. Each formatted word will be printed. 

#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

using namespace std;

void charstats (string, int&, int&, int&, int&); //void function to count the number of non-whitespaces, letters, vowels and digits found in the file
string format (string); //value returning function that will format the word read from the file
int  newwordsize (string, int); //value returning function that will count the number of characters found in the word after formatting, used to calculate average length of formatted words

int main()
{
  string word, line, largestWord, largestFormat; //declaration of string variables used in the program
  int charcount =0, digitcount =0, lettercount =0, vowelcount =0, sum =0, wordcount =0, size, count; //declareation of integer values used in the program
  double average; //declaration of double varaible used to represent average length of formatted words
  int forendl;//used to format printed words
 cout << endl << "Edsel Villadoz, Assignment #3" << endl << endl;//displays name and assignment number

  cout << "Word List" << endl;//prints title for word list
  cin >> word;//reads for word from file
  largestWord = word;//used to find largest word before formatting in file
  largestFormat = line;//used to find largest word after formatting in file
  forendl = 0;//used to count up to four so that end of line can be placed after fourth word for formatting

  while (cin)
    {
      wordcount++;//used to count words
      forendl++;
      charstats(word, charcount, digitcount, lettercount, vowelcount);//executes void function to count nummber of non-whitespaces, letters, vowels and digits

      line = format(word);//executes value returning function to format words

      if (word.length() > largestWord.length())//used to determine largest word before formatting
	 largestWord = word;

      if (line.length() > largestFormat.length())//used to determine largest word after formatting
	 largestFormat = line;

      cout << left << setw(20);//prints formatted words
      cout << line;
      
     if (forendl == 4)//if it is the fourth word, the end of line line will be reached and counter will restart
       {
        cout << endl;
        forendl = 0;
       }

      size = newwordsize(line, count);// executes value returning function to find character count of formatted words used to find average length of formatted words
      sum = sum + size;//used to calculate sum of length of formatted words

      cin >> word;//reads for next word in file
    }

  average = sum / double(wordcount);//used to calculate average length of formatted words
  cout << endl << endl;
  cout << "Non-whitspace characters: " << charcount << endl;//prints non-whitespace character count
  cout << "Letters: " << lettercount << endl;//prints letter count
  cout << "Digits: " << digitcount << endl;//prints digit count
  cout << "Vowels: " << vowelcount << endl;//prints vowel count
  cout << "Longest word before formatting: " << largestWord << endl;//prints longest word before formatting
  cout << "Longest word after formatting: " << largestFormat << endl;//prints longest word after formatting
  cout << "Average length of formatted words: " << average << endl;//prints average length of formatted words
return 0;
}

void charstats (string word, int& charcount, int& digitcount, int& lettercount, int& vowelcount)//function that counts non-whitespaces, letters, vowels and digits
{

    for (int i = 0; i < word.length(); i++)
	{
	  charcount++;

	  if (isalpha(word[i]))
	    lettercount++;

	  if (isdigit(word[i]))
	    digitcount++;

	  if (word[i] == 'A' || word[i] =='a' || word[i] == 'E' || word[i] == 'e' || word[i] == 'I' || word[i] == 'i' || word[i] == 'O' || word[i] == 'o' || word[i] == 'U' || word[i] == 'u')
	    vowelcount++;
	}

}

string format (string word)//function that formats words
{ 
  string line = "";

      for ( int i = 0; i < word.length(); i++)
	{
	  word[i] = tolower(word[i]);
	  if (isalnum(word[i]))
	      line +=  word[i];

          else
	   if (isalnum(word[i+1]) && isalnum(word[i-1]))
		line += word[i];
	}

  return line;
}

int newwordsize (string line, int count =0)//function that counts new length of words after formatting to be used in calculation of average length of formatted words
{
  for (int i = 0; i < line.length(); i++)
    count++;

  return count;
}

