/*
 ID: Aryaman Mishra [03aryam1]
 TASK: money
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 5 2023
// PROBLEM ID           :    Money
// PROBLEM DESCRIPTION  :    Find the number of combinations
//                           possible of coins to produce a
//                           certain number
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A


#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Declare USACO I/O Files
    ifstream fin("money.in");
    ofstream fout("money.out");
    
    // Declare Variables
    long long numCoins, money, temp, coinAdd;
    
    // Input First Variables
    fin >> numCoins >> money;
    
    // Make Dependent Variables
    long long coins[numCoins];
    long long curBal[money+1];
    
    // Input Rest Of Input
    for (long long i = 0; i <= money; i++)
    {
        if (i < numCoins)
        {
            fin >> coins[i];
        }
        curBal[i] = 0;
    }
    curBal[0] = 1;
    
    // Dynamic Programming
    for (long long i = 0; i < numCoins; i++)
    {
        coinAdd = coins[i];
        for (long long j = 0; j <= money; j++)
        {
            if (j + coinAdd <= money)
            {
                curBal[j + coinAdd] += curBal[j];
            }
            
        }
    }

    // Output Results
    fout << curBal[money] << endl;;
}
