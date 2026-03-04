/*
 ID: Aryaman Mishra [03aryam1]
 TASK: runround
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 2 2023
// PROBLEM ID           :    Runround
// PROBLEM DESCRIPTION  :    Print the next biggest
//                           runround number
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A

#include <bits/stdc++.h>
using namespace std;

// Declare Variables
vector<int> numRan;
int lengthList, numStart;
vector<int> mainVec;
unordered_set<int> mainSet;

// Return true if the number is runround
bool run(int counter, int num, int curNum)
{
    if (counter > 0 && num == numStart)
    {
        if (counter == mainVec.size())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    for (int i = 0; i < numRan.size(); i++)
    {
        if (numRan[i] == num)
            return false;
    }
    
    numRan.push_back(num);
    return run(counter + 1, mainVec[(curNum + int(num % lengthList)) % lengthList], (curNum + int(num % lengthList)) % lengthList);
}
int main()
{
    // Declare Variables
    ifstream fin ("runround.in");
    ofstream fout ("runround.out");
    int numRun;
    bool found = false;
    string numString;
    
    fin >> numRun;
    
    // Run while number is found
    while (!found)
    {
        mainVec.clear();
        mainSet.clear();
        numRan.clear();
        
        numRun++;
        numString = to_string(numRun);
        for (int i = 0; i < numString.length(); i++)
        {
            mainVec.push_back(numString[i] - 48);
            mainSet.insert(numString[i] - 48);
        }
        
        // If all numbers are unique
        if (mainVec.size() == mainSet.size())
        {
            lengthList = mainVec.size();
            numStart = mainVec[0];
            found = run(0, mainVec[0], 0);
        }

    }
    
    // Output Results
    fout << numRun << endl;
    
    return 0;
}
