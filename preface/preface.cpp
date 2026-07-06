/*
 ID: Aryaman Mishra [03aryam1]
 TASK: preface
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <unordered_set>
using namespace std;

// Make base arrays
int mainNums[] = {1000,   900, 500,  400,  100,  90,  50,   40,   10,   9,   5,   4,    1};
string mainDi[] = {"M",  "CM", "D",  "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV",  "I"};

int main()
{
    // Setup Variables For Usaco
    ifstream fin ("preface.in");
    ofstream fout ("preface.out");
    
    // Declare Variables
    int curNum;
    string holdRoman = "";
    char roman[] = {'I','V','X','L', 'C','D','M'};
    int numLet[] = { 0,  0,  0,  0,   0,  0,  0};
    int numMax;
    
    // Calculate All Roman Numerals
    // And store in one big string
    fin >> numMax;
    for (int i = 1; i <= numMax; i++)
    {
        curNum = i;
        for (int j = 0; j < 13; j++)
        {
            int count = 0;
            while (curNum - mainNums[j] >= 0 && count < 3)
            {
                count++;
                curNum -= mainNums[j];
                holdRoman += mainDi[j];
            }
        }
    }
    
    // Calculate how many I, V etc there are
    for (int i = 0; i < holdRoman.length(); i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (roman[j] == holdRoman[i])
            {
                numLet[j]++;
                break;
            }
        }
    }
    
    // Print results
    for (int i = 0; i < 7; i++)
    {
        if (numLet[i] != 0)
        {
            fout << roman[i] << " " << numLet[i] << endl;
        }
    }
    
    // Exit Code
    return 0;
}
