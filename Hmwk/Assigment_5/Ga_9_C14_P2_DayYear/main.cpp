/* 
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/19/21  4:00pm
    Gaddis 9th C134P2
Challenge 2: "Day of the Year"
Write a class named DayOfYear that takes an integer representing the day of the year
and translates it to a string consisting of the month and day of the month.
*/

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "DOTY.h"
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
       //Declare variables here
    int dayNum;
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    cout << "Enter a day of the year from 1-365: ";
    cin >> dayNum;
    DOTY d(dayNum);
    d.setend();
    d.setmonth();
    d.print();

    return 0;
}
