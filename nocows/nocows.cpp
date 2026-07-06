/*
 ID: Aryaman Mishra [03aryam1]
 TASK: nocows
 LANG: C++
 */
// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 5 2023
// PROBLEM ID           :    Cow Pedigrees
// PROBLEM DESCRIPTION  :    Find the total number of different
//                           possible pedigress with a given height
//                           and nodes mod 9901
// LINES OF CODE        :    59

#include <bits/stdc++.h>
using namespace std;

// Declare DP Array
int mainArr[200][200];

int main()
{
    // Declare USACO I/O
    ifstream fin("nocows.in");
    ofstream fout("nocows.out");
    
    // Declare Variables
    short n, height;
    
    // Input Node and Height
    fin >> n >> height;
    
    // Run through all possible num of nodes
    for (short i = 1; i <= n; i += 2)
    {
        // Run through all heights
        for (short j = 1; j <= height; j++)
        {
            // If there is one node, there is
            // only 1 possible way to do so
            if (i == 1) mainArr[i][j] = 1;
            else
            {
                // Make short trees
                for (short k = 1; k < i; k++)
                {
                    // Main DP thing
                    mainArr[i][j] += mainArr[k][j-1]*mainArr[i-k-1][j-1];
                    mainArr[i][j] %= 9901;
                }
            }
        }
    }
    
    // Output Result
    fout << (mainArr[n][height] - mainArr[n][height-1] + 9901) % 9901 << endl;
        
    return 0;
}
