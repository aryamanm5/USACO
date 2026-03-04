/*
 ID: Aryaman Mishra [03aryam1]
 TASK: humble
 LANG: C++
 */

// NAME                 :   Aryaman Mishra
// GROUP                :   Discrete Math
// LAST MODIFIED        :   August 23 2023
// PROBLEM ID           :   Humble Numbers
// PROBLEM DESCRIPTION  :   Find the Nth humble number in a set of S
// TOTAL LINES          :   63

#include <bits/stdc++.h>
using namespace std;

// Declare Global Variables
using ll = long long;
ll humble[100001], prime[101], last[100001];
const ll maxi = 223372036854775806;
int numPrime, maxH;

int main()
{
    // Declare USACO I/O
    ifstream fin ("humble.in");
    ofstream fout ("humble.out");
    humble[0] = 1;
    
    // Take in inputs
    fin >> numPrime >> maxH;
    for (int i = 0; i < numPrime; i++)
    {
        fin >> prime[i];
    }
    
    // Run through all possible humble numbers
    for (int i = 1; i <= maxH; i++)
    {
        // Make current, biggest possible
        humble[i] = maxi;
        
        // Go through all primes
        for (int j = 0; j < numPrime; j++)
        {
            // Find prime* humble until it exceeds biggest current humble
            while (last[j] < i and prime[j] * humble[last[j]] <= humble[i-1])
            {
                last[j]++;
            }
            
            // If new humble is bigger than last humble
            if(prime[j] * humble[last[j]] > humble[i-1])
            {
                // Store humble numebr
                humble[i] = min(humble[i], prime[j] * humble[last[j]]);
            }
        }
    }
    
    // Output Results
    fout << humble[maxH] << endl;
}
