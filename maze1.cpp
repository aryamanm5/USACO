/*
 ID: Aryaman Mishra [03aryam1]
 TASK: maze1
 LANG: C++
 */

// NAME                 :   Aryaman Mishra
// GROUP                :   Discrete Math
// LAST MODIFIED        :   August 26 2023
// PROBLEM ID           :   Overfencing
// PROBLEM DESCRIPTION  :   Find the spot where it is hardest
//                          to escape from in a maze
// TOTAL LINES          :   130

#include <bits/stdc++.h>
using namespace std;

// Declare Gloval Variables
int numArr[205][80], escapeX[2], escapeY[2];
string storeStr;
vector<string> storeVec;
int escapeC = 0, curMax = 0;
int width, height;

// Go through all possiblites of escape
void recurse(int i, int j, int num)
{
    
    // If out of bounds, exit
    if (i <= 0 or i >= 2*height or j <= 0 or j >= 2*width) return;
    
    // If num is greater than the one already there, exit
    if (numArr[i][j] and numArr[i][j] <= num) return;
    
    // If number is smaller, store the number
    if (num < numArr[i][j] or numArr[i][j] == 0) numArr[i][j] = num;
    
    // Move North
    if (storeVec[i-1][j] == ' ')
        recurse(i-2, j, num+1);
    
    // Move South
    if (storeVec[i+1][j] == ' ')
        recurse(i+2, j, num+1);
    
    // Move East
    if (storeVec[i][j+1] == ' ')
        recurse(i, j+2, num+1);
    
    // Move West
    if (storeVec[i][j-1] == ' ')
        recurse(i, j-2, num+1);
}

int main()
{
    // USACO I/O
    ifstream fin ("maze1.in");
    ofstream fout ("maze1.out");
    
    // Take in inputs
    fin >> width >> height;
    for (int i = 0; i <= 2*height+1; i++)
    {
        getline(fin, storeStr);
        
        if (i != 0)
        {
            storeVec.push_back(storeStr);
        }
    }
    
    // Escape Finders
    // Find any escape on the sides
    for (int i = 1; i < 2*height; i += 2)
    {
        // If escape on the left, store
        if(storeVec[i][0] == ' ')
        {
            escapeX[escapeC] = i;
            escapeY[escapeC] = 1;
            escapeC++;
        }
        
        // If escape on the right, save
        if(storeVec[i][2*width] == ' ')
        {
            escapeX[escapeC] = i;
            escapeY[escapeC] = 2*width-1;
            escapeC++;
        }
    }
    
    // Find any escapes on the top or bottom
    for (int i = 1; i < 2*width; i += 2)
    {
        // If escape on the top save
        if(storeVec[0][i] == ' ')
        {
            escapeX[escapeC] = 1;
            escapeY[escapeC] = i;
            escapeC++;
        }
        
        // If escape on the bottom, save
        if(storeVec[2*height][i] == ' ')
        {
            escapeX[escapeC] = 2*height-1;
            escapeY[escapeC] = i;
            escapeC++;
        }
        
    }
    
    // Recurse through each enterance
    recurse(escapeX[0], escapeY[0], 0);
    recurse(escapeX[1], escapeY[1], 0);
    
   // Calcute highest distacne
    for (int i = 1; i < 2*height+1; i += 2)
    {
        for (int j = 1; j < 2*width+1; j += 2)
        {
            curMax = max(curMax, numArr[i][j]);
        }
    }
    
    // Output Results
    fout << ++curMax << endl;
}
