/*
 ID: Aryaman Mishra [03aryam1]
 TASK: concom
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Discrete Math
// LAST MODIFIED        :    August 28 2023
// PROBLEM ID           :    Controlling Companies
// PROBLEM DESCRIPTION  :    Find which companies control which by assesing
//                           company percentages
// LINES OF CODE        :    82

#include <bits/stdc++.h>
using namespace std;

// Declare Global Variables
set<vector<int>> mainSet;
vector<pair<int,int>> info[101];
int owner[101], here[101];

void addParent(int i)
{
    // If parent already added, end
    if (here[i]) return;
    
    // Parent here
    here[i] = 1;
    
    // Run through all possiblites
    for (pair<int,int> x : info[i])
    {
        owner[x.first] += x.second;
        // If there is a parent for this, add the new company
        // To thier list of holdings
        if (owner[x.first] > 50)
        {
            addParent(x.first);
        }
    }
}
int main()
{
    // Declare USACO I/O
    ifstream fin ("concom.in");
    ofstream fout ("concom.out");
    
    // Declare Variables
    int numCom, com1, com2, per;
    
    // Take in USACO Input
    fin >> numCom;
    for (int i = 0; i < numCom; i++)
    {
        fin >> com1 >> com2 >> per;
        info[com1].push_back({com2, per});
    }
    
    // Run through all possiblites of companies
    for (int i = 1; i <= 100; i++)
    {
        // Set both arrays to 0
        memset(here, 0, sizeof(here));
        memset(owner, 0, sizeof(owner));
        
        // Create a company
        addParent(i);
        
        for (int j = 1; j <= 100; j++)
        {
            // If a company is owned, output it
            if (here[j] and i != j)
            {
                fout << i << " " << j << endl;
            }
        }
    }

    // End Program
    return 0;
}
