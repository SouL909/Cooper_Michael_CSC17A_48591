/* 
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/20/21  9:00am
    Gaddis 9th C14P3
Challenge 4: "Day of the Year Modification"
 * Design a class called numDays.
*/

//System Libraries
#include <iostream>   //Input/Output Library
#include <math.h>
//User Libraries
#include "NumDy.h"
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    float hours1, hours2;
    
    //Initialize variables here
    cout << "Enter the number of hours: ";
    cin >> hours1;
    cout << "Enter the number of hours: ";
    cin >> hours2;
    
    //Map inputs to outputs here, i.e. the process
    // Define two objects of WorkHours
    NumDays one(hours1), two(hours2);

    cout << "One: " << one.getDays() << " day/days" << endl;
    cout << "Two: " << two.getDays() << " day/days" << endl;

    // Demonstrate addition and subtraction operators

    // Define a third and fourth object to be used for further operator demonstrations
    

    //Display the results
    
    
    return 0;
}

