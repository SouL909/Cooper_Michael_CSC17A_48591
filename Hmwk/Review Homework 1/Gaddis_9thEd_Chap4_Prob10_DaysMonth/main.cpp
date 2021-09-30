/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Sept 4, 20120, 6:30 PM
 * Purpose:  Chap 4 Prob 10 (Days in a month during a particular year)
 * 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cmath>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants, no Global Variables are allowed
//Math/Physics/Conversions/Higher Dimensions - i.e. PI, e, etc...

//Function Prototypes

//Execution Begins Here!
int main(int argc, char** argv) {
    //PROBLEM:
    //Write a program that asks the user to enter the month 
    //(letting the user enter an integer in the range of 1 through 12) 
    //and the year. The program should then display the number of days in that month.

    //Declare variables here
    unsigned short int month,year;

    //Initialize variables here
    cout << "Enter month (1 - 12): "; 
    cin >> month;
    cout << "Enter year: "; 
    cin >> year;

    //Display the results
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "31 days";
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << "30 days";
        break;

case 2:
    //Leap year
    if (year % 100 == 0)
    {
        if (year % 400 == 0)
            cout << "29 days" << endl;
        else
            cout << "28 days" << endl;
    }
    else if (year % 100 != 0)
    {
        if (year % 4 == 0)
            cout << "29 days" << endl;
        else
            cout << "28 days" << endl;
    }
    break;

default:
    cout << "Invalid entry, please try again." << endl;
   }

    //Exit stage right or left!
    return 0;
}
