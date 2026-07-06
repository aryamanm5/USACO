/*
 ID: Aryaman Mishra [03aryam1]
 TASK: agrinet
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Advanced CS
// LAST MODIFIED        :    May 10 2024
// PROBLEM ID           :    Agri-Net
// PROBLEM DESCRIPTION  :    Finds the most efficent route to
//                           supply an entire town with internet
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A
// LINES OF CODE        :    74

#include <fstream>
#include <iostream>

using namespace std;

int main() 
{
    // USACO I/O
    ifstream fin("agrinet.in");
    ofstream fout("agrinet.out");
    
    int matrix[101][101], dist[101];
    bool visited[101];
    int numFarms, maxi = 1000000, curBranch = 1, total = 0, storeJ;
    
    // Take in input
    // Adjust everything by 1 because 0 does not work
    fin >> numFarms;
    for (int i = 1; i <= numFarms; i++)
    {
        for (int j = 1; j <= numFarms; j++)
        {
            fin >> matrix[i][j];
        }
    }
    
    // Fill each vector with storage variables
    // Fill starts variables first
    for (int i = 1; i <= numFarms; i++) {
        dist[i] = maxi;
        visited[i] = false;
    }
    
    // Adjust indexing to start from 1 because of adjust
    dist[1] = 0;
    visited[1] = true;
    for (int i = 1; i < numFarms; i++)
    {
        for (int j = 1; j <= numFarms; j++)
        {
            dist[j] = min(dist[j], matrix[curBranch][j]);
        }
        
        storeJ = -1;
        for (int j = 1; j <= numFarms; j++)
        {
            if (!visited[j] and (storeJ == -1 or dist[j] < dist[storeJ]))
            {
                storeJ = j;
            }
        }
        curBranch = storeJ;
        total += dist[storeJ];
        visited[storeJ] = true;
    }
    fout << total << endl;
    
    return 0;
}
