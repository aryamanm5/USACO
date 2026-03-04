/*
 ID: Aryaman Mishra [03aryam1]
 TASK: nuggets
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 11 2023
// PROBLEM ID           :    Nuggets
// PROBLEM DESCRIPTION  :    Find the biggest number of nuggets
//                           you can't buy with McD's options
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Declare USACO I/O
    ifstream fin ("nuggets.in");
    ofstream fout ("nuggets.out");
    
    // Declare Variables
    //             256*256 = 65536
    int maxNum, mainArr[65536] = {0}, temp, nuggy[10];
    
    // Input in from USACO
    fin >> maxNum;
    for (int i = 0; i < maxNum; i++)
    {
        fin >> nuggy[i];
        mainArr[nuggy[i]] = 1;
    }
    
    // DP
    // Run through the entire array
    for (int i = 0; i < 65536; i++)
    {
        // If nuggets possible, add all boxes of nuggets
        if (mainArr[i])
        {
            for (int j = 0; j < maxNum; j++)
            {
                // If in range, make the possible nugget true
                if (i+nuggy[j] < 65536)
                {
                    mainArr[i + nuggy[j]] = 1;
                }
            }
        }
    }
    
    // Run loop to print result
    for (int i = 65535; i >= 0; i--)
    {
        if (!mainArr[i])
        {
            // If number possible print number
            if (i < 65535)
            {
                fout << i << endl;
            }
            
            // If no bounds exist print 0
            else
            {
                fout << 0 << endl;
            }
            
            // Exit Program
            return 0;
        }
    }
    
    return 0;
}
