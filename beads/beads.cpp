// NAME                     :   Aryaman Mishra
// GROUP                    :   Discrete Math
// LAST MODIFIED            :   1 October 2023
// PROBLEM ID               :   Poly Eval Algo
// PROBLEM DESCRIPTION      :   Finds the polynominal with a certain x value
// SOURCES                  :   DM Textbook
// PEOPLE WHO HELPED ME     :   David Shen, David Li, Kenny Seybold
// PEOPLE I HELPED          :   David Shen, David Li, Kenny Seybold

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> coff;
int degree, xVal;

int pow(int x, int n)
{
    int p = x, k = 1;
    
    while (k < n)
    {
        p = p * x;
        k = k + 1;
    }
    
    return p;
}

string nextSub(string bin)
{
    int k = bin.length()-1;
    
    while (k >= 1 and bin[k] == '1')
    {
        k--;
    }
    
    if (k >= 1)
    {
        bin[k] = '1';
        
        for (int j = k+1; j < bin.length(); j++)
        {
            bin[j] = '0';
        }
        
        return bin;
    }
    else
    {
        cout << "\nThis string contains all 1s" << endl;
        return bin;
    }
}
int polyEval()
{
    int s = coff[0], k = 1;
    
    cout << endl;
    while (k <= degree+1)
    {
        cout << "S" << k-1 << " = " << s << endl;
        s += coff[k]*pow(xVal, k);
        k = k + 1;
    }
    
    return s;
}

int horners()
{
    int s = coff[degree], k = 1;
    cout << "S: " << s << endl;
    cout << endl;
    
    while (k <= degree)
    {
        cout << "H" << k-1 << " = "  << s << endl;
        s  = (s*xVal) + coff[degree-k];
        k = k + 1;
    }
    cout << "H" << k-1 << " = " << s << endl;
    return s;
//    (2,6,9,20)
}

int main()
{

    int tempNum;
    string tempStr = "y", firstBin;
    
    cout << "Aryaman Mishra\nDiscrete Math\nNext Subset Algortim" << endl << endl;
    
    
    while (tempStr == "y")
    {
        cout << "Enter in string: ";
        cin >> firstBin;

        cout << nextSub(firstBin) << endl;
        
        cout << "\nRun Next Subset Algortihm Program Again (y/n)?  ";
        cin >> tempStr;
        cout << endl;
    }
    
    /*
    while (tempStr == "y")
    {
        cout << "Degree of the polynomial:  ";
        cin >> degree;

        cout <<  "Value of x:  ";
        cin >> xVal;

        for (int i =0; i <= degree; i++)
        {
            cout << "Coefficient of the x^" << i << " term:  ";
            cin >> tempNum;
            coff.push_back(tempNum);
        }
        reverse(coff.begin(), coff.end());
        tempNum = horners();
        cout << endl << tempNum << endl;
        
        cout << "\nRun Next Subset Algortihm Program Again (y/n)?  ";
        cin >> tempStr;
        cout << endl;
        coff.clear();
        
    }
     */
}

