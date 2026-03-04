/*
 ID: Aryaman Mishra [03aryam1]
 TASK: stamps
 LANG: C++
*/

// NAME                     :    Aryaman Mishra
// GROUP                    :    Binary
// LAST MODIFIED            :    April 18 2023
// PROBLEM ID               :    Stamps
// PROBLEM DESCRIPTION      :    Finds the first cent number that cannot
//                               be made with the given stamps
// SOURCES USED             :    Tutorials Point (C++ Data Types) (Short)
// PEOPLE I HELPED ME       :    N/A
// PEOPLE WHO HELPED ME     :    N/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Declare USACO input output variables
    ifstream fin("stamps.in");
    ofstream fout("stamps.out");
    
    // Declare Variables
    int numStamps, givenStamps;
    const int maxArrSize = 2000000, shortMax = 32767;
    
    // Use short because of limited memory
    // And intaialze to 0 and Max Value
    short mainArr[maxArrSize][2] = {0};
    
    for (int i = 0 ; i < maxArrSize; i++)
    {
        mainArr[i][0] = 0;
        mainArr[i][1] = shortMax;
    }
    
    // Take in inputs from USACO
    fin >> numStamps >> givenStamps;
    
    // Declare Stamp array
    int stamps[givenStamps];
    
    // Take in stamps from USACO
    for (int i = 0 ; i < givenStamps; i++)
    {
        fin >> stamps[i];
        mainArr[stamps[i]][0] = 1;
        mainArr[stamps[i]][1] = 1;
    }
    
    // Dynamic Program
    for (int i = 0; i < maxArrSize; i++)
    {
        // If cent # exists
        if (mainArr[i][0])
        {
            // If the number of stamps is less than used
            if (mainArr[i][1] < numStamps)
            {
                // Add each stamp to current number
                for (int j = 0; j < givenStamps; j++)
                {
                    // If stamp fits in the array
                    if (stamps[j]+i < maxArrSize)
                    {
                        // Make stamp number true
                        mainArr[stamps[j]+i][0] = 1;
                        
                        // Put the minimum number of stamps to get
                        // To current number, if smaller number already
                        // there, dont change, else add 1 to stamps used
                        if (mainArr[stamps[j]+i][1] > mainArr[i][1] + 1)
                        {
                            mainArr[stamps[j]+i][1] = mainArr[i][1] + 1;
                        }
                    }
                }
            }
        }
    }
    
    // Print out results
    for (int i = 1; i < maxArrSize; i++)
    {
        if (!mainArr[i][0])
        {
            fout << i-1 << "\n";
            return 0;
        }
    }
}
