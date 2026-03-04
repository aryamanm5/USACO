/*
 ID: Aryaman Mishra [03aryam1]
 TASK: ratios
 LANG: C++
 */

// NAME                 :   Aryaman Mishra
// GROUP                :   Discrete Math
// LAST MODIFIED        :   August 14 2023
// PROBLEM ID           :   Feed Ratios
// PROBLEM DESCRIPTION  :   Find the most optimal ratios to
//                          feed the cows for dinner
// TOTAL LINES          :   135

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // USACO I/O Files
    ifstream fin ("ratios.in");
    ofstream fout ("ratios.out");
    
    // Make final array
    short ratio[4];
    for (int i = 0; i < 4; i++)
    {
        ratio[i] = 32667;
    }
    
    // Declare Variables
    short first[3], second[3], third[3], main[3], mainTest[3];
    
    // Take in Inputs
    fin >> main[0] >> main[1] >> main[2];
    fin >> first[0] >> first[1] >> first[2];
    fin >> second[0] >> second[1] >> second[2];
    fin >> third[0] >> third[1] >> third[2];
    
    // Run through all possible combinations
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            for (int k = 0; k < 100; k++)
            {
                // Make temp array with combinations
                mainTest[0] = first[0]*i + second[0]*j + third[0]*k;
                mainTest[1] = first[1]*i + second[1]*j + third[1]*k;
                mainTest[2] = first[2]*i + second[2]*j + third[2]*k;
                
                // If else statements check wheater array is divisible
                // Many due to /0 error
                if (main[0] != 0)
                {
                    if (mainTest[0] % main[0] == 0)
                    {
                        mainTest[0] /= main[0];
                    }
                    else continue;
                }
                else
                {
                    if (mainTest[0] != 0) continue;
                }
                
                if (main[1] != 0)
                {
                    if (mainTest[1] % main[1] == 0)
                    {
                        mainTest[1] /= main[1];
                    }
                    else continue;
                }
                else
                {
                    if (mainTest[1] != 0)
                    {
                        continue;
                    }
                    
                }
                
                if (main[2] != 0)
                {
                    if (mainTest[2] % main[2] == 0)
                    {
                        mainTest[2] /= main[2];
                    }
                    else continue;
                }
                else
                {
                    if (mainTest[2] != 0) continue;
                }
                
                // Find the common ratio
                int numFirst = max(mainTest[1], max(mainTest[2], mainTest[0]));
                bool fail = false;
                
                // If common ratio exists, keep "fail" false
                for (int i = 0; i < 3; i++)
                {
                    if (mainTest[i] == numFirst or (mainTest[i] == 0 and main[i] == 0))
                    {
                        continue;
                    }
                    else
                    {
                        fail = true;
                        break;
                    }
                }

                // If common ratio exists, save it
                if (!fail)
                {
                    if (ratio[0]+ratio[1]+ratio[2] > i+j+k and i+j+k != 0)
                    {
                        ratio[0] = i;
                        ratio[1] = j;
                        ratio[2] = k;
                        ratio[3] = numFirst;
                        
                    }
                }
                
            }
        }
    }
    
    // Output data
    if (ratio[0] < 32667) fout << ratio[0] << " " << ratio[1] << " " << ratio[2] << " " << ratio[3] << endl;
    else fout << "NONE" << endl;
}
