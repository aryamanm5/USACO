/*
 ID: Aryaman Mishra [03aryam1]
 TASK: comehome
 LANG: C++
 */

// NAME                 :   Aryaman Mishra
// GROUP                :   Discrete Math
// LAST MODIFIED        :   August 14 2023
// PROBLEM ID           :   Bessie Come Home
// PROBLEM DESCRIPTION  :   Find the first cow to reach the barn
//                          for dinner
// TOTAL LINES          :   90

#include <bits/stdc++.h>
using namespace std;

// Declare Adjaceny Matrix
short adArr[52][52];

int main()
{
    // USACO I/O Files
    ifstream fin ("comehome.in");
    ofstream fout ("comehome.out");
    
    // Intialize Array to max
    for (int i = 0; i < 52; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            adArr[i][j] = 32766;
        }
    }
    
    // Declare Variables
    int numPaths;
    fin >> numPaths;
    char start, end;
    short path, x, y, minNum = 32766;
    
    // Take in inputs
    for (int i = 0; i < numPaths; i++)
    {

        fin >> start >> end >> path;
        
        // Convert Char to Number
        if (start >= 65 and start <= 90) x = start-39;
        else x = start-97;
        
        if (end >= 65 and end <= 90) y = end - 39;
        else y = end - 97;
        
        // Put number in adjacency matrix
        adArr[x][y] = min(adArr[x][y], path);
        adArr[y][x] = min(adArr[y][x], path);

    }

    // Use the Floyd-Warshall Algorithm
    for (int k = 0; k < 52; k++)
    {
        for (int i = 0; i < 52; i++)
        {
            for (int j = 0; j < 52; j++)
            {
                // Shorter path?
                if (adArr[i][k] + adArr[k][j] < adArr[i][j])
                {
                    adArr[i][j] = adArr[i][k] + adArr[k][j];
                }
            }
        }
    }
    
    // Find the smallest path to Z
    for (int i = 26; i < 51; i++)
    {
        if (adArr[i][51] < minNum)
        {
            minNum = adArr[i][51];
            end = i;
        }
    }

    // Output details
    end += 39;
    fout << end << " " << minNum << endl;
}
