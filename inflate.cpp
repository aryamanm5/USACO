/*
 ID: Aryaman Mishra [03aryam1]
 TASK: inflate
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 10 2023
// PROBLEM ID           :    Inflate
// PROBLEM DESCRIPTION  :    Finds the maximum score possible
//                           in a USACO Competition
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Declare USACO I/O
    ifstream fin("inflate.in");
    ofstream fout("inflate.out");
    
    // Setup variables
    int maxMin, numProb;
    int prob[100001][2], mainArr[100001] = {0}, maxScore = 0;
    
    // Take in input
    fin >> maxMin >> numProb;
    maxMin++;
    
    // Take in score inputs
    for (int i = 0; i < numProb; i++)
    {
        // minutes then score
        fin >> prob[i][1] >> prob[i][0];
        mainArr[prob[i][0]] = prob[i][1];
    }
    
    // Dynamic Programing
    for (int i = 0; i < maxMin; i++)
    {
        // If nothing in array move on
        if (mainArr[i] == 0) continue;
        
        // Add each score
        for (int j = 0; j < numProb; j++)
        {
            // minutes under bound
            if (i + prob[j][0] < maxMin)
            {
                mainArr[i + prob[j][0]] = max(mainArr[i+prob[j][0]], mainArr[i]+prob[j][1]);
            }
        }
    }
    
    // Sort the array to get the biggest num
    sort(mainArr, mainArr+maxMin);
    
    // Output results
    fout << mainArr[maxMin-1] << endl;
    
    // End Code
    return 0;
}

