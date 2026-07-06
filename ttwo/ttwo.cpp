/*
 ID: Aryaman Mishra [03aryam1]
 TASK: ttwo
 LANG: C++
 */

// NAME                 :   Aryaman Mishra
// GROUP                :   Discrete Math
// LAST MODIFIED        :   August 13 2023
// PROBLEM ID           :   The Tamworth Two
// PROBLEM DESCRIPTION  :   Calculate number of minutes till
//                          FJ meets his cow in a 10*10 grid
// TOTAL LINES          :   211

#include <bits/stdc++.h>
using namespace std;

// Declare Global Variables
short mainArr[10][10];
short farmerX, farmerY, cowX, cowY;

// Moves the requested character in the right direction
void move(short x, short y, char who)
{
    short numTest = mainArr[x][y];
    short nextX = x;
    short nextY = y;
    
    // North
    if (numTest == 0)
    {
        nextX--;
    }
    
    // East
    else if (numTest == 1)
    {
        nextY++;
    }
    
    // South
    else if (numTest == 2)
    {
        nextX++;
    }
    
    // West
    else
    {
        nextY--;
    }
    
    // If Obstacle, turn character
    if (mainArr[nextX][nextY] == 5 or nextX < 0 or nextY < 0 or nextY > 9 or nextX > 9)
    {
        mainArr[x][y] = (numTest + 1) % 4;
        
    }
    else
    {
        // Update respective cordinates
        if (who == 'f')
        {
            farmerX = nextX;
            farmerY = nextY;
        }
        else
        {
            cowX = nextX;
            cowY = nextY;
        }
        
        // Move character on grid
        mainArr[nextX][nextY] = numTest;
        mainArr[x][y] = 4;
    }
}
// Checks if the Cow or the Farmer should go first
char first()
{
    // If Cow and Farmer are on the same row just one apart
    if (cowX == farmerX and (cowY-1 == farmerY or cowY+1 == farmerY))
    {
        // If Cow infront of Farmer
        if (cowY > farmerY)
        {
            // If going east, let cow go first
            if (mainArr[farmerX][farmerY] == 1)
            {
                return 'c';
            }
            // If going west, let farmer go first
            return 'f';
        }
        
        // If Farmer infront of cow
        else
        {
            // If going east, let farmer go first
            if (mainArr[cowX][cowY] == 1)
            {
                return 'f';
            }
            // If going west, let cow go first
            return 'c';
        }
        
        
    }
    // If Cow and Farmer are on the Column just one apart
    else if (cowY == farmerY and (cowX-1 == farmerX or cowX+1 == farmerX))
    {
        // If cow infront of Farmer
        if (cowX > farmerX)
        {
            // If they going north let farmer go first
            if (mainArr[cowX][cowY] == 0)
            {
                return 'f';
            }
            // If going south, let cow go first
            return 'c';
        }
        // If farmer infront of cow
        else
        {
            // If going north, let cow go first
            if (mainArr[farmerX][farmerY] == 0)
            {
                return 'c';
            }
            // If going south, let farmer go first
            return 'f';
        }
    }
    return 'f';
}

int main()
{
    // USACO I/O Files
    ifstream fin ("ttwo.in");
    ofstream fout ("ttwo.out");
    
    // String for input
    string inp;
    
    // Minute counter variable
    int min = 0;
    
    // Get input
    for (short i = 0; i < 10; i++)
    {
        fin >> inp;
        for (short j = 0; j < 10; j++)
        {
            // If open, call it 4
            if (inp[j] == '.')
            {
                mainArr[i][j] = 4;
            }
            // If blocked, call it 5
            else if (inp[j] == '*')
            {
                mainArr[i][j] = 5;
            }
            // If farmer, store farmer info
            else if (inp[j] == 'F')
            {
                mainArr[i][j] = 0;
                farmerX = i;
                farmerY = j;
            }
            // If cow, store cow info
            else
            {
                mainArr[i][j] = 0;
                cowX = i;
                cowY = j;
            }
        }
    }
    
    // Run Simulation
    while (cowX != farmerX or cowY != farmerY)
    {
        // If farmer goes first, let farmer go first
        if (first() == 'f')
        {
            move(farmerX, farmerY, 'f');
            move(cowX, cowY, 'c');
        }
        
        // If cow should go first, then let cow go
        else
        {
            move(cowX, cowY, 'c');
            move(farmerX, farmerY, 'f');
        }
        
        // Add one minute
        min++;
        
        // Exit if simulation has started to repeat
        if (min == 160000) break;
    }
    
    // Output results
    if (min < 160000) fout << min << endl;
    else fout << 0 << endl;
}
