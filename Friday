/*
ID: Aryaman Mishra [03aryam1]
TASK: friday
LANG: C++
*/
// NAME                 : Aryaman Mishra
// GROUP                : Tissues
// LAST MODIFIED        : Jun 14 2022
// PROBLEM ID           : Friday the Thirtheen
// PROBLEM DESCRIPTION  : Calculate Frequency of Dates With 13th
// SOURCES              : Google Calendar
#include <iostream>
#include <fstream>
#include <string>
#include <array>

using namespace std;

class myClass
{
    public:
      ifstream fin;
      ofstream fout;
      int days[7];
      int firstDayY = 2;
      int firstDayM = 2;
      int month;
      int year = 1900;
      int totalNumYears, theDay;

    void getInput()
    {
      fin.open("input.txt");
      fin >> totalNumYears;
      totalNumYears = year + totalNumYears;
      fin.close();
      for (int i = 0; i < 7; i++)
        {
          days[i] = 0;
        }
    }
    int getDayNum(int dayNum)
      {
        while (dayNum >= 7)
        {
          dayNum = dayNum - 7;
        }
      return dayNum;
      }
    void firstDayCalc(int day)
    {

      if (month == 4 || month == 6 || month == 9 || month == 11)
      {
        // 30 day months
        // add 18 to get to the next month
        firstDayM = day + 18;
        
      }
      else if (month == 2)
      {
        // 28 and 29 day months
        // checks if a year is a century or not
        // If century, check if divisible by 400 if not check if divisble by 4
        if ((((year%100 == 0) && (year%400 == 0))) || ((year%100 != 0) && (year%4 == 0)))
          {
            //29 days / leap year
            firstDayM = day + 17;
          }

        else
        {
          //28 days
          firstDayM = day + 16;
        }
      }// else if brakcet
      else
      {
        //31 days
        firstDayM = day + 19;
      }

      // gets the Day of the 1st of month
      firstDayM = getDayNum(firstDayM);
    }
    void monthCalc()
    {
      // gets the Day which the 13th lands on
      
      theDay = firstDayM + 12;
      theDay = getDayNum(theDay);

      // adds one to the Day
      days[theDay] = days[theDay] + 1;
      // moves on to next Month
      firstDayCalc(theDay);
      }

    void yearCalc()
    {
        for (month = 1; month <= 12; month++)
          {
            monthCalc();
          }
      year++;
    }
    
    void printArray()
    {
      fout.open("output.txt");
      for (int i = 0; i < 7; i++)
        {
          fout << days[i] << " ";
        }
        fout << "\n";
        fout.close();
    }
    
};
int main() {
  myClass runner;
  runner.getInput();
  while (runner.year < runner.totalNumYears)
    {
      runner.yearCalc();
    }
  runner.printArray();

  return 0;
}
