/*
ID: Aryaman Mishra [03aryam1]
TASK:ride
LANG: C++                 
*/
// NAME                 : Aryaman Mishra
// GROUP                : Tissues
// LAST MODIFIED        : 15 March 2022
// PROBLEM ID           : Ride
// PROBLEM DESCRIPTION  : Prompts the user for two strings, multiples their numbers and then 
//						 compares the mod of the two strings and if they equal each 
//						 other, prints “GO” otherwise “STAY”
// SOURCES              : Mr. Cardwell, USACO Website, Geeks for Geeks, Java at Point, Tutorials Point, 
//                                  Cplusplus.com, W3Schools, Online GDB, edcuba.com, Java2blog,
//                                  Chryswoods.com, Stack Overflow, Delft Stack             
// PEOPLE WHO HELPED ME : Mr. Cardwell, David Li, Ethan Jastifer
// PEOPLE WHO I HELPED  : David Li, Ethan Jastifer, Noah Keithley, Ivan Tai, Izzy Tai, Tanisha Patel
 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Class to make code shorter
// Takes in input string, runs it and stores answer in "add"
class findproduct
	{
	public:

		// USACO Input Stored Here
		string inputone;

		// Alphabet is used to help the computer know what letter corresponds to what number"
		string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

		// This is the variable where the final number will be stored.
		int add = 1;

		// This object performs the actual conversion.
		void findnum()
		{
	
			// This first for loop loops through the input given and looks at each character in the string
			for(int i = 0; i < inputone.length(); i++)
			{
				char firstcom = inputone[i];

				// Second for loop loops through the alphabet variable
				for (int j = 0; j < alphabet.length(); j++)
				{				
					char secondcom = alphabet[j];

					// This tries to find if a letter in the alphabet equals the string
					if (firstcom == secondcom)
					{						
						int justthere = j+1;
						add = add * justthere;
					}
				}		
			}
		}
	};

int main() 
	{
	// Setup for USACO
	ofstream fout ("ride.out");
	ifstream fin ("ride.in");

	// Defines Classes
	findproduct productfinder;

	// Input from USACO
   	fin >> productfinder.inputone;
 	productfinder.findnum();

	// Stores answer for later
	int firstnum = productfinder.add % 47;

	// Resets the variable above
	productfinder.add = 1;

	// Step Repeats to find the second int 
   	fin >> productfinder.inputone;
 	productfinder.findnum();
	int secondnum = test.add % 47;

	// Compares the first number and second number
	if (firstnum == secondnum)
	{
		fout << "GO" << endl;
	}
	else	
	{
		fout << "STAY" << endl;
	}
  return 0;	
	}
