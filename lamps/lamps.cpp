/*
 ID: Aryaman Mishra [03aryam1]
 TASK: lamps
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 11 2023
// PROBLEM ID           :    Lamps
// PROBLEM DESCRIPTION  :    Print all combos of lamps that
//                           fit after button preses
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A

#include <bits/stdc++.h>
using namespace std;

// Declare Variables
set<string> printSet;
vector<int> on, off, lamps(0);
int numLamps, numBut, temp;

// Button A, Changes status of all lamps
vector<int> butA(vector<int> workLamp)
{
    for (int i = 0; i < workLamp.size(); ++i)
    {
        if (workLamp[i])
        {
            workLamp[i] = 0;
        }
        else
        {
            workLamp[i] = 1;
        }
    }
    return workLamp;
}

// Button B, changes status of all odd numbered lamps
vector<int> butB(vector<int> workLamp)
{
    for (int i = 0; i < workLamp.size(); i+=2)
    {
        if (workLamp[i])
        {
            workLamp[i] = 0;
        }
        else
        {
            workLamp[i] = 1;
        }
    }
    return workLamp;
}

// Button C, changes status of all even numbered lamps
vector<int> butC(vector<int> workLamp)
{
    for (int i = 1; i < workLamp.size(); i+=2)
    {
        if (workLamp[i])
        {
            workLamp[i] = 0;
        }
        else
        {
            workLamp[i] = 1;
        }
        
    }
    return workLamp;
}

// Button D, changes every 3K+1 lamp
vector<int> butD(vector<int> workLamp)
{
    for (int i = 0; 3*i < workLamp.size(); i++)
    {
        if (workLamp[3*i])
        {
            workLamp[3*i] = 0;
        }
        else
        {
            workLamp[3*i]  = 1;
        }
    }
    return workLamp;
}

// Recursive function that finds all possibilites of button presses
void recurse(vector<int> workLamp, int counter, bool a, bool b, bool c, bool d)
{
    if (counter > numBut) return;
    
    // If even num presses because even means useless button
    if (((numBut - counter) % 2 == 0))
    {
        string mainString = "";
        bool checker = true;
        // Check if any ones that should be on are off
        for (int i = 0; i < on.size(); i++)
        {
            if (!workLamp[on[i]-1])
            {
                checker = false;
            }
        }
        // Check if any ones that should be off are on
        for (int i = 0; i < off.size(); i++)
        {
            if (workLamp[off[i]-1])
            {
                checker = false;
            }
        }
        
        // If all on/off matches, then add to answer
        if (checker)
        {
            for (int i = 0; i < numLamps; i++)
            {
                if (workLamp[i])
                {
                    mainString += "1";
                }
                else
                {
                    mainString += "0";
                }
            }
            // Put answer in a set
            printSet.insert(mainString);
            
            // If button presses have reached, end recure
            if (counter == numBut) return;
        }
    }
    
    // If button X has not been pressed, press it, then recurse
    if (!a)
    {
        recurse(butA(workLamp), counter + 1, 1, b, c, d);
    }
    if (!b)
    {
        recurse(butB(workLamp), counter + 1, a, 1, c, d);
    }
    if (!c)
    {
        recurse(butC(workLamp), counter + 1, a, b, 1, d);
    }
    if (!d)
    {
        recurse(butD(workLamp), counter + 1, a, b, c, 1);
    }
}

int main()
{
    // Declare USACO I/O
    ifstream fin ("lamps.in");
    ofstream fout ("lamps.out");
    
    // Take in USACO inputs
    fin >> numLamps >> numBut >> temp;
    
    // While there are on inputs, take them in
    while (temp != -1)
    {
        on.push_back(temp);
        fin >> temp;
    }
    fin >> temp;
    
    // While there are off inputs, take them in
    while (temp != -1)
    {
        off.push_back(temp);
        fin >> temp;
    }
    
    // Create vector with all lamps on
    lamps.resize(numLamps,1);
    
    // Go find all possible button clicks
    recurse(lamps, 0, 0, 0, 0, 0);
    
    // If nothing was found in recursive function, not possible
    if (!printSet.size())
    {
        fout << "IMPOSSIBLE\n";
    }
    
    // Print all numbers found in recursive function
    for (string x : printSet)
    {
        fout << x << endl;
    }
    
}
