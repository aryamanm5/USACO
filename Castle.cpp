/*
 ID: Aryaman Mishra [03aryam1]
 TASK: castle
 LANG: C++
*/

// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 2 2023
// PROBLEM ID           :    Castle
// PROBLEM DESCRIPTION  :    Calculate rooms in a castle
//                           and roomsizes after a wall is remove
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A

#include <bits/stdc++.h>
using namespace std;

// Make Struct
struct Square
{
    bool N = false;
    bool S = false;
    bool E = false;
    bool W = false;
    bool here = false;
    long long floorNum;
};

// Declare Variables
long long width, height;
Square castle[50][50];
long long roomsize[2500];

// Make Recursive Function
void number(long long floorNum, long long x, long long y)
{
    long long w;

    
    if(castle[x][y].here)
    {
        return;
    }
    
    castle[x][y].here = true;
    castle[x][y].floorNum = floorNum;
    roomsize[floorNum]++;
    
    
    if(x > 0 && !(castle[x][y].W))
        number(floorNum, x-1, y);
    
    if(x+1 < width && !(castle[x][y].E))
        number(floorNum, x+1, y);
    
    if(y > 0 && !(castle[x][y].N))
        number(floorNum, x, y-1);
    
    if(y+1 < height && !(castle[x][y].S))
        number(floorNum, x, y+1);
}

int main()
{
    // Declare Variables
    long long wallType, m = 0, n = 0;
    long long bestX, bestY;
    char bestD;
    ifstream fin ("castle.in");
    ofstream fout ("castle.out");

    // Take in inputs
    fin >> width >> height;
    for(long long y  =0; y< height; y++)
    {
        for(long long x = 0; x< width; x++)
        {
            fin >> wallType;
            if (wallType - 8 >= 0)
            {
                castle[x][y].S = true;
                wallType -= 8;
            }
            if (wallType - 4 >= 0)
            {
                castle[x][y].E = true;
                wallType -= 4;
            }
            if (wallType - 2 >= 0)
            {
                castle[x][y].N = true;
                wallType -= 2;
            }
            if (wallType - 1 >= 0)
            {
                castle[x][y].W = true;
                wallType -= 1;
            }
            
        }
    }
    
    // Calculate All Room Sizes
    long long nroom = 0;
    for(long long y = 0; y< height; y++)
    {
        for(long long x = 0; x < width; x++)
        {
            if(!castle[x][y].here)
                number(nroom++, x, y);
        }
            
    }
        
    // Output biggest room
    long long bigroom = 0;
    for (long long i = 0; i < nroom; i++)
    {
        bigroom = max(roomsize[i], bigroom);
    }
    
    
    for(long long x=0; x<width; x++)
        for(long long y=height-1; y>=0; y--)
        {
            if(y > 0 && castle[x][y].floorNum != castle[x][y-1].floorNum)
            {
                n = roomsize[castle[x][y].floorNum] + roomsize[castle[x][y-1].floorNum];
                if(n > m) {
                    m = n;
                    bestX = x;
                    bestY = y;
                    bestD = 'N';
                }
            }
            if(x+1 < width&& castle[x][y].floorNum != castle[x+1][y].floorNum) {
                n = roomsize[castle[x][y].floorNum] + roomsize[castle[x+1][y].floorNum];
                if(n > m) {
                    m = n;
                    bestX = x;
                    bestY = y;
                    bestD = 'E';
                }
            }
        }
    
    // Output Info
    fout << nroom << endl;
    fout <<  bigroom << endl;
    fout << m << endl;
    fout <<  bestY+1 << " " << bestX+1 << " " << bestD << endl;
    
    return 0;
}
