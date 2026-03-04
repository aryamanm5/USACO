/*
 ID: Aryaman Mishra [03aryam1]
 TASK: rockers
 LANG: C++
 */

// NAME                 :   Aryaman Mishra
// GROUP                :   Discrete Math
// LAST MODIFIED        :   August 14 2023
// PROBLEM ID           :   Raucous Rockers
// PROBLEM DESCRIPTION  :   Find the maximum number of songs to
//                          Put on a CD
// TOTAL LINES          :   66

#include <bits/stdc++.h>
using namespace std;

// Declare Global Variables
int numSongs, maxMin, numDisks;
int mainArr[30];
int ans = 0;

// Recurse through all song possiblites
// Current Songs | Number of Songs Used | Number of Disks Used | Current Disk Size
void recurse(int i, int j, int k, int l)
{
    // If over, end dfs
    if (k > numDisks or l > maxMin) return;
    
    // If CDs are full, find best answer
    if (i == numSongs+1)
    {
        ans = max(ans, j);
        return;
    }
    
    // Use different CD for song
    recurse(i+1, j, k, l);
    
    // Add song to current disk
    recurse(i+1, j+1, k, l + mainArr[i]);
    
    // Add song to new disk
    recurse(i+1, j+1, k+1, mainArr[i]);
    
}

int main()
{
    // USACO I/O Files
    ifstream fin ("rockers.in");
    ofstream fout ("rockers.out");
    
    // Take in inputs
    fin >> numSongs >> maxMin >> numDisks;
    for (int i = 1; i <= numSongs; i++)
    {
        fin >> mainArr[i];
    }
    
    // 1 song, 0 used songs, First disk, 0 disk
    recurse(1, 0, 1, 0);
    
    // Output answer
    fout << ans << endl;
}
