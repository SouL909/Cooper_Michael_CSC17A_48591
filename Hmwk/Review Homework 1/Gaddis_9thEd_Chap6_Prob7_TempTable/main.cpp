/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Sept 5, 2021, 11:45 PM
 * Purpose:  Chap 6 Prob 7 (Temp Table)
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
float celsius(int);

//Execution Begins Here!

int main(int argc, char** argv) {
    //PROBLEM:
    /*Write a function named Celsius that accepts a Fahrenheit temperature 
     *as an argument. The function should return the temperature, 
     *converted to Celsius. Demonstrate the function by calling it 
     *in a loop that displays a table of the Fahrenheit temperatures 
     *0 through 20 and their Celsius equivalents.
     */

    //Set the random number seed
    
    //Declare variables here
    //Initialize variables here
    cout << "-----------------------------------|\n";
    cout << "Fahrenheit     | Celsius\n";
    cout << "-----------------------------------|\n";

    //Map inputs to outputs here, i.e. the process
    //Display the results
    for (int F = 0; F <= 20; F++) {
    cout << "      " << setw(2) << F;
    cout << "          ";
    cout << setw(3) << celsius(F) << endl;
    }
    

    //Exit stage right or left!
    return 0;
}

float celsius(int F)
{
	return (5.0 * (F - 32))/9;
}