/*
 ID: Aryaman Mishra [03aryam1]
 TASK: zerosum
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 11 2023
// PROBLEM ID           :    ZeroSum
// PROBLEM DESCRIPTION  :    Prints all combo of nums
//                           that calculate to 0
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A

#include <bits/stdc++.h>

using namespace std;

// Declare Global Variables
vector<string> mainVec, allNums;
vector<int> numInString;
vector<char> thingsInString;
set<string> mainSet;
int mainNum;

// Create function which creates all possibilites
void recurse(int counter, string mainString)
{
    // If all number have been added to string
    // Add it to a vector
    if (counter == mainNum)
    {
        mainVec.push_back(mainString);
        return;
    }
    
    // Take current string, add the next number with a +, - and " "
    recurse(counter + 1, mainString + " " + allNums[counter-1]);
    recurse(counter + 1, mainString + "+" + allNums[counter-1]);
    recurse(counter + 1, mainString + "-" + allNums[counter-1]);
}

int main()
{
    // Declare USACO I/O
    ifstream fin ("zerosum.in");
    ofstream fout ("zerosum.out");

    // Take in maximum number for Zerosum
    fin >> mainNum;
    
    // Declare Variables
    int mainArr[mainNum], count;
    char charNum;
    string numWork, holder;
    
    // Create a string vector with all the numbers
    for (int i = 2; i <= mainNum; ++i)
    {
        allNums.push_back(to_string(i));
    }
    
    // Find all possibilites
    recurse(1, "1");
    
    // Calculate all the eqautions we created
    for (int i = 0; i < mainVec.size(); ++i)
    {
        // Reset Variables
        count = 0;
        numWork = mainVec[i];
        
        // Clear calculation vectors
        numInString.clear();
        thingsInString.clear();
        
        // Run through the string
        // "1-2-3+4"
        for (int j = 0; j < mainNum*2-1; ++j)
        {
            charNum = numWork[j];
            
            // If its an operation add it to operation vector
            if (charNum == '+' or charNum == '-' or charNum == ' ')
            {
                thingsInString.push_back(charNum);
            }
            
            // It is a number add to number
            else
            {
                holder = "";
                holder.push_back(charNum);
                
                // If the next operation is space, combine the numbers
                while (j+2 < mainNum*2-1 && numWork[j+1] == ' ')
                {
                    holder += numWork[j+2];
                    j += 2;
                }
                numInString.push_back(stoi(holder));
            }
        }
        
        // Current count is first number present
        count += numInString[0];
        
        // Go through rest of the string adding/subtracting
        for (int k = 1; k < numInString.size(); ++k)
        {
            // If add then add number
            if (thingsInString[k-1] == '+')
            {
                count += numInString[k];
            }
            // If subtract
            if (thingsInString[k-1] == '-')
            {
                count -= numInString[k];
            }
        }
        
        // If it is a zeroSum, add to answer set
        if (count == 0)
        {
            mainSet.insert(numWork);
        }
        
    }
    
    // Print out all possible combos
    for (string x: mainSet)
    {
        fout << x << endl;
    }
    
}
