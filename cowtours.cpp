/*
 ID: Aryaman Mishra [03aryam1]
 TASK: cowtour
 LANG: C++
*/

// NAME                 :    Aryaman Mishra
// GROUP                :    Advanced CS
// LAST MODIFIED        :    May 10 2024
// PROBLEM ID           :    Cow Tours
// PROBLEM DESCRIPTION  :    Find a way to connect exactly two pastures in the input
//                           with a cow path so that the new combined field has the smallest
//                           possible diameter of any possible pair of connected pastures.
//                           Output that smallest possible diameter.
//                           and roomsizes after a wall is remove
// LINES OF CODE        :    220

#include <unordered_set>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <limits.h>
using namespace std;

int mainField[150][150],  places[2][150], beenHere[150];
double pasture1[150][150], pasture2[150][150], sPasture1[150][150], sPasture2[150][150];
vector<int> conPasture1, conPasture2;
vector<double> pasture2Dis;
unordered_set<int> pastureFound;
int justHold, pasture1len = 0, pasture2len = 0;
string store;
int n, maxLen = INT_MAX;

double maxArr(int whatArray, int index)
{
    double maxNum = 0;
    if (whatArray == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (sPasture1[index][i] != maxLen and sPasture1[index][i] > maxNum)
            {
                maxNum = sPasture1[index][i];
            }
            if (sPasture1[i][index] != maxLen and sPasture1[i][index] > maxNum)
            {
                maxNum = sPasture1[i][index];
            }
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (sPasture2[index][i] != maxLen and sPasture2[index][i] > maxNum)
            {
                maxNum = sPasture2[index][i];
            }
            if (sPasture2[i][index] != maxLen and sPasture2[i][index] > maxNum)
            {
                maxNum = sPasture2[i][index];
            }
        }
    }
    return maxNum;
}
double howFar(int from, int to)
{
    int x = abs(places[0][from] - places[0][to]);
    int y = abs(places[1][from] - places[1][to]);
    return sqrt(pow(x,2)+pow(y,2));
}
void looker(int j)
{
    if (beenHere[j])
    {
        return;
    }
    beenHere[j] = 1;
    pastureFound.insert(j);
    for (int i = 0; i < n; i++)
    {
        if (i == j) continue;
        if (mainField[j][i])
        {
            looker(i);
        }
    }
}

int main()
{
    ifstream fin ("cowtour.in");
    FILE * fout = fopen("cowtour.out", "w");
    
    fin >> n;
    for (int i = 0; i < n; i++)
    {
        fin >> places[0][i];
        fin >> places[1][i];
    }
    for (int i =0; i < n; i++)
    {
        fin >> store;
        for (int j = 0; j < n; j++)
        {
            mainField[i][j] = store[j]-'0';
        }
    }

    looker(0);
  
    
    
    for (int i = 0; i < n; i++)
    {
        if (pastureFound.count(i))
        {
            
            for (int j = 0; j < n; j++)
            {
                if (mainField[i][j])
                    pasture1[pasture1len][j] = howFar(i,j);
                
            }
            pasture1len += 1;
            conPasture1.push_back(i);
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                if (mainField[i][j])
                    pasture2[pasture2len][j] = howFar(i,j);
            }
            pasture2len += 1;
            conPasture2.push_back(i);
        }
        
    }


    // Floyed Marshall
    // dist(i,j) is "best" distance so far from vertex i to vertex j
    // Start with all single edge paths.
    for (int i = 0; i < pasture1len; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pasture1[i][j] != 0)
                sPasture1[i][j] = pasture1[i][j];
            else
                sPasture1[i][j] = maxLen;
        }
    }
    for (int k = 0; k < pasture1len; k++)
    {
        for (int i = 0; i < pasture1len; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (sPasture1[i][k] + sPasture1[k][j] < sPasture1[i][j])
                    sPasture1[i][j] = sPasture1[i][k] + sPasture1[k][j];
            }
        }
    }
    
    // Floyed Marshall
    // dist(i,j) is "best" distance so far from vertex i to vertex j
    // Start with all single edge paths.
    for (int i = 0; i < pasture2len; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pasture2[i][j] != 0)
                sPasture2[i][j] = pasture2[i][j];
            else
                sPasture2[i][j] = maxLen;
        }
    }
    for (int k = 0; k < pasture1len; k++)
    {
        for (int i = 0; i < pasture1len; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (sPasture2[i][k] + sPasture2[k][j] < sPasture2[i][j])
                    sPasture2[i][j] = sPasture2[i][k] + sPasture2[k][j];
            }
        }
    }
    

    
    double current1Max = 0;
    double maxDia = maxLen;
    for (int i = 0; i < pasture2len; i++)
    {
        pasture2Dis.push_back(maxArr(2,conPasture2[i]));
    }
    for (int i = 0; i < pasture1len; i++)
    {
        current1Max = maxArr(1, i);
        for (int j = 0; j < pasture2len; j++)
        {
            //cout << conPasture1[i] << " " << conPasture2[j] << endl;
            maxDia = min(maxDia, current1Max + howFar(conPasture1[i],conPasture2[j]) + pasture2Dis[j]);
        }
    }
    cout << "Pasture 2 " << pasture2len << endl;
    if (pasture1len == 1)
    {
        maxDia = 1;
    }
    fprintf (fout, "%.6f", maxDia);
    fprintf (fout, "\n");
}

