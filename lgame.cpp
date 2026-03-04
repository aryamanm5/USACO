/*
 ID: Aryaman Mishra [03aryam1]
 TASK: lgame
 LANG: C++
 */

// NAME                 :    Aryaman Mishra
// GROUP                :    Binary
// LAST MODIFIED        :    April 10 2023
// PROBLEM ID           :    Inflate
// PROBLEM DESCRIPTION  :    Finds the maximum score possible
//                           in a USACO Competition
// PEOPLE WHO I HELPED  :    N/A
// PEOPLE WHO HELPED ME :    N/A

#include <bits/stdc++.h>
using namespace std;

// Create Global Variables
string mainStr, firstStr, temp;
int highestNum, counted;
vector<pair<int, string>> mainPair;

// Create map to calculate values
map<char, int> mainMap = {
    {'a', 2}, {'b', 5}, {'c', 4}, {'d', 4}, {'e', 1}, {'f', 6}, {'g', 5},
    {'h', 5}, {'i', 1}, {'j', 7}, {'k', 6}, {'l', 3}, {'m', 5}, {'n', 2},
    {'o', 3}, {'p', 5}, {'q', 7}, {'r', 2}, {'s', 1}, {'t', 2}, {'u', 4},
    {'v', 6}, {'w', 6}, {'x', 7}, {'y',  5}, {'z', 7},
};

// Function that checks if "check" contains letters found in the input string
// Returns -1 if check is not valid
int valid(string check)
{
    // Create temp variables
    string tempy = firstStr;
    int count = 0;
    
    // If the length is greater, return
    if (check.length() > firstStr.length()) return -1;
    
    // Find matching characters, returns -1 if char not found or the
    // value of the word if all characters were found
    for (int i = 0; i < check.length(); i++)
    {
        // Add value of each letter
        count += mainMap[check[i]];
        
        // Check if string is present
        auto index = tempy.find(check[i]);
        if( index != string::npos)
        {
            tempy.erase(index, 1);
            continue;
        }
        else
        {
            return -1;
        }
    }
    
    // Return value of word "check"
    return count;
}

int main()
{
    // Declare USACO I/O
    ifstream fin("lgame.in");
    ifstream dict("lgame.dict");
    ofstream fout("lgame.out");
    
    // Get first word from USACO dictionary
    getline(dict, temp);
    
    // Get characters from USACO
    getline(fin, firstStr);

    // While space in USACO dict, keeping going with words
    while (temp != ".")
    {
        // Get value of word from USACO dict
        counted = valid(temp);
        
        // If the value of the word is valid, keep going
        if (counted > 0)
        {
            // Make a pair of the word and its value
            mainPair.push_back(make_pair(counted, temp));
            
            // If the word can be added to another word while being valid
            // add the word with a new value
            int curLen = mainPair.size();
            for (int i = 0; i < curLen-1; i++)
            {
                counted = valid(mainPair[i].second + temp);
                if (counted > 0)
                    mainPair.push_back(make_pair(counted, mainPair[i].second + " " + temp));
            }
        }
        
        // Get next word
        getline(dict, temp);
        
    }
    
    // Sort the pairs by word value
    sort(mainPair.begin(), mainPair.end());
    
    // Store highestValue as the highestValue of a word
    highestNum = mainPair[mainPair.size()-1].first;
    
    // Output the highest value of a word
    fout << highestNum << endl;
    
    // Print all words that match the highest value
    for (int i = 0; i < mainPair.size(); i++)
    {
        if (mainPair[i].first >= highestNum)
            fout << mainPair[i].second << endl;
    }
    
    // Exit Program
    return 0;
}
