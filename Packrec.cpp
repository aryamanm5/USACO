/*
 ID: Aryaman Mishra [03aryam1]
 TASK: packrec
 LANG: C++
 */

// NAME                 :   Aryaman Mishra
// GROUP                :   Discrete Math
// LAST MODIFIED        :   August 15 2023
// PROBLEM ID           :   Packing Rectangles
// PROBLEM DESCRIPTION  :   Find the smallest area where you can
//                          fit 4 rectangles and print out its
//                          width and height
// TOTAL LINES          :   187

#include <bits/stdc++.h>
using namespace std;

// Declare Global Variables
set<string> store;
vector<int> mainVec, holdVec;
vector<vector<int>> c, mainComb;
set<vector<int>> maxD, pComb;
string mainNum = "";
int maxNum = INT_MAX;

// Create all combinaitons of height and width
void allCom(int num)
{
    if (mainNum.size() == 4)
    {
        for (int i = 0; i < mainNum.size(); i++)
        {
            for (int j = i+1; j < mainNum.size(); j++)
            {
                if (mainNum[i] == mainNum[j])
                {
                    return;
                }
            }
        }
        store.insert(mainNum);
        return;
    }
    
    // If all possible combinations, return;
    if (num == 16) return;
    
    mainNum += to_string(num%4);
    allCom(num+1);
    mainNum.pop_back();
    allCom(num+1);
}

// Method for finding smallest area for rect
void save(int width, int height)
{
    // If total area is less, clear all data
    if (width*height < maxNum)
    {
        maxNum = width*height;
        maxD.clear();
        maxD.insert({min(width,height),max(width, height)});
    }
    
    // If area matches, add width and height data;
    else if (width*height == maxNum)
    {
        maxD.insert({min(width,height),max(width, height)});
    }
    
    return;
}

// Create sets of all numbers
void allFour(int num)
{
    if (num >= 4)
    {
        pComb.insert(holdVec);
        return;
    }
    
    // Recursively Add and subtract numbers
    holdVec.push_back(num);
    allFour(num+1);
    holdVec.pop_back();
    allFour(num+1);
    pComb.insert({});
    
}

int main()
{
    // Declare USACO I/O Files
    ifstream fin ("packrec.in");
    ofstream fout ("packrec.out");
    
    // Declare width and height variables
    int w, h;
    int w1,w2,w3,w4;
    int h1,h2,h3,h4;
    
    // Run methods
    allCom(0);
    allFour(0);
    
    // Take in inputs
    for (int i = 0; i < 4; i++)
    {
        fin >> w >> h;
        mainComb.push_back({w,h});
    }
    
    // Run through all possibiltes
    for (string x : store)
    {
        for (auto j : pComb)
        {
            // Clear current combination vector
            c.clear();
            
            // Create c vector with w/h possibilites
            for (int i = 0; i < 4; i++)
            {
                c.push_back(mainComb[x[i]-'0']);
            }
            for (auto x : j)
            {
                c[x] = {c[x][1], c[x][0]};
            }
            
            // Hold variables for ease when making combinations
            w1 = c[0][0]; w2 = c[1][0]; w3 = c[2][0]; w4 = c[3][0];
            h1 = c[0][1]; h2 = c[1][1]; h3 = c[2][1]; h4 = c[3][1];
            
            // first arrangment
            w = w1+w2+w3+w4;
            h = max(max(h1,h2),max(h3,h4));
            save(w,h);
            
            // second arrangment
            w = max(w1+w2+w3,w4);
            h = max(max(h1,h2),h3)+h4;
            save(w,h);
            
            // third arrangment
            w = max(w1+w2,w3)+w4;
            h = max(max(h1+h3,h2+h3),h4);
            save(w,h);
            
            // fourth arrangment
            w = w1+w2+max(w3,w4);
            h = max(max(h1,h3+h4),h2);
            save(w,h);
            
            // fifth arrangment
            h = max(h1+h3,h2+h4);
            
            // Find all different width possiblites
            if(h3>=h2+h4)
                w = max(max(w1,w3+w2),w3+w4);
            
            if(h3>h4 and h3<h2+h4)
                w = max(max(w1+w2,w2+w3),w3+w4);
            
            if(h4>h3 and h4<h1+h3)
                w = max(max(w1+w2,w1+w4),w3+w4);
            
            if(h4>=h1+h3)
                w = max(max(w2,w1+w4),w3+w4);
            
            if (h3 == h4)
                w = max(w1+w2,w3+w4);
            
            save(w,h);
        }
        
    }
    
    // Output results
    fout << maxNum << endl;
    for (auto x : maxD)
    {
        fout << x[0] << " " << x[1] << endl;
    }
}
