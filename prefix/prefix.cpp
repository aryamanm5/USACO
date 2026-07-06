/*
 ID: Aryaman Mishra [03aryam1]
 TASK: prefix
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 23 2023
// PROBLEM ID           :    Longest Prefix
// PROBLEM DESCRIPTION  :    Find the number of the longest prefix
//                           in a string of letters
// LINES OF CODE        :    75

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // USACO I/O
    ifstream fin ("prefix.in");
    ofstream fout ("prefix.out");
    
    // Declare Variables
    const int maxSize = 200000;
    char charArr[maxSize];
    string mainStr = "", temp;
    vector<string> wordCheck;
    int tempCount = 0, best = 0, access;
    
    // Input from USACO
    fin >> temp;
    while (temp != ".")
    {
        wordCheck.push_back(temp);
        fin >> temp;
    }
    while (getline(fin, temp))
    {
        mainStr += temp;
    }
    
    // Initalize Array
    int intArr[maxSize] = {0};
    intArr[0] = 1;
    
    // Run through the entire string
    for (int i = 0; i < mainStr.length(); i++)
    {
        // If something is there go
        if (intArr[i])
        {
            // Go through all the prefixs
            for (auto checker : wordCheck)
            {
                
                int access = i + checker.size();
                if (access < maxSize)
                {
                    // Check if the prefix is possible
                    if (mainStr.substr(i, access-i) == checker)
                    {
                        intArr[access] = 1;
                        // Store farthest prefix
                        best = max(best, access);
                    }
                }
            }
        }
    }
    
    // Output results
    fout << best << endl;
    return 0;
}
