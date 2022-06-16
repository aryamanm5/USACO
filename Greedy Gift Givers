/*
ID: Aryaman Mishra [03aryam1]
TASK: gift1
LANG: C++
*/
// NAME                 : Aryaman Mishra
// GROUP                : Tissues
// LAST MODIFIED        : Jun 15 2022
// PROBLEM ID           : Greedy Gift Givers
// PROBLEM DESCRIPTION  : Create a Bank System To Manage A Gift Giving Session
// SOURCES              : StackOverFlow
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include<string.h>

using namespace std;

/*
 //prints Array for test purposes
 for (int i = 0; i < np; i++)
 {
    cout << nameOfPeople[i] << " " << balance[i] << endl;
 }
 */

int main() {

    ifstream fin;
    ofstream fout;
    string lineRead, tempStore, giver;
    int np, totalMoney, numOfRec, moneySplit, checker;
    
    fin.open("gift1.in");
    if (fin.is_open())
    {
        // get number of people
        fin >> tempStore;
        np = stoi(tempStore);
        
        //define array of names and money
        string nameOfPeople[np];
        // makes the balance array
        int balance[np];
        for (int i = 0; i < np; i++)
        {
            balance[i] = 0;
        }
        
        // put names of people into nameOfOPeople
        for (int i = 0; i < np; i++)
        {
            fin >> tempStore;
            nameOfPeople[i] = tempStore;
        }
        
        // main for loop which goes through each person
        for (int i = 0; i < np; i++)
        {
            // defines whos giving, to how many and how much
            fin >> giver;
            fin >> totalMoney;
            fin >> numOfRec;
            // amount each person shall get
            if (numOfRec != 0)
            {
                moneySplit = totalMoney/numOfRec;
            }
            else
            {
                moneySplit = 0;
            }
            // used to make code work
            checker = 0;
            // for loop that goes through the recipents
            for (int j = 0; j < numOfRec; j++)
            {
                // stores recipents name
                fin >> tempStore;
                // for loop to find the place of the recipent
                for (int k=0;k < np; k++)
                {
                    // if recipents is giver, add remaninder and subtract total
                    if (nameOfPeople[k].compare(giver) == 0 && checker == 0 )
                    {
                        if (numOfRec != 0)
                        {
                            balance[k] = balance[k] + totalMoney%numOfRec - totalMoney;
                            checker = 1;
                        }
                        else
                        {
                            balance[k] = balance[k] - totalMoney;
                            checker = 1;
                        }
                    }
                    // if recipent is found, add moneySplit to thier balance
                    if (nameOfPeople[k].compare(tempStore) == 0)
                    {
                        balance[k] = balance[k] + moneySplit;

                    }
                }
            }
        }
        fin.close();
        // takes the answer and puts it into output file
        fout.open("gift1.out");
        for (int i = 0; i < np; i++)
        {
           fout << nameOfPeople[i] << " " << balance[i] << endl;
        }
        fout.close();
    }
    else
    {
        cout << "failed";
    }
    return 0;
}
