/*
 ID: Aryaman Mishra [03aryam1]
 TASK: fracdec
 LANG: C++
*/

// NAME                 :    Aryaman Mishra
// GROUP                :    Discrete Math
// LAST MODIFIED        :    August 11 2023
// PROBLEM ID           :    Fractions to Decimal
// PROBLEM DESCRIPTION  :    Calculate rooms in a castle
//                           and roomsizes after a wall is remove
// LINES OF CODE        :    79

#include <bits/stdc++.h>
using namespace std;

// Repeat Store Array; Offset by 1
int mainArr[200000] = {0};

int main()
{
    // USACO I/O Files
    ifstream fin ("fracdec.in");
    ofstream fout ("fracdec.out");
    
    // Declare Variables
    vector<int> mainVec;
    int num, den, add, counter = 1;
    string mainStr = "";
    
    // Take in USACO input
    fin >> num >> den;
    
    // Make numbers before the decimal point
    mainStr += to_string(num/den);
    mainStr += ".";
    add = mainStr.size();
    
    // Mod num and then store it
    num = num % den;
    mainArr[num] = counter;
    counter++;

    // While number doesn't repeat or end
    while (num != 0)
    {
        // Mulitpy then store divison
        num *= 10;
        mainStr += to_string(num/den);
        num = num % den;
        
        // If new num already seen before, end
        if (mainArr[num] != 0)
        {
            // Add repeating brackets
            mainStr.insert(mainArr[num]+add-1, "(");
            mainStr += ")";
            num = 0;
        }
        
        // Add used num to list
        mainArr[num] = counter;
        counter++;
    }
    
    // If nothing after the dot, add a 0
    if (mainStr[mainStr.size()-1] == '.') mainStr += "0";
    
    // Output Results
    for (int i = 0; i < mainStr.size(); i++)
    {
        if (i % 76 == 0 and i != 0) fout << "\n";
        fout << mainStr[i];
    }
    fout << endl;
    
    return 0;
}
