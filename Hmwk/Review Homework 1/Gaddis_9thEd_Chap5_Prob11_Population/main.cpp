/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Sept 5, 2021, 12:00 PM
 * Purpose:  Chap 5 Prob 11 (Population)
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
    /* Write a program that will predict the size of a population of organisms. 
     * The program should ask the user for the starting number of organisms, 
     * their average daily population increase (as a percentage), and the number 
     * of days they will multiply. A loop should display the size of the population for each day.
     */
    
    //Set the random number seed
    
    //Declare variables here
    float sNumOrg,  //Starting number of organisms
          avDPI,    //Average Daily Population Increase
          sDPI;     //Size of Daily Population Increase

    unsigned short int numDTM;     //Number of days to multiply

    //Initialize variables here
    //Map inputs to outputs here, i.e. the process
    cout << "Enter the starting number of organisms: ";

    while (!(cin >> sNumOrg || sNumOrg < 2)) {
        cout << "Starting number must be 2 or greater." << endl;
        cout << "Enter the starting number of organisms: ";
        cin.clear();
        cin.ignore();
    }
    cout << "Enter average daily population increase (%):"<< endl;
    while (!(cin >> avDPI) || avDPI < 0) {
        cout << "Average daily population increase\n"
             << "must be greater than 0. Enter average\n"  
             << "daily population increase (%): ";
        cin.clear();
        cin.ignore();
    }

    avDPI *= .01;
    cout << "Enter number of days they will multiply: ";

    while(!(cin >> numDTM) || numDTM < 1) {
        cout << "Number of days must NOT be less than 1.\n"
             << "Enter number of days they will multiply: \n";
        cin.clear();
        cin.ignore();
    }
    //Display the results
    for(int i = 0; i < numDTM; i++ ) {
        cout << "Population size for day " << (i + 1);
        cout << ": " << sNumOrg << endl;
        sNumOrg += (sNumOrg * avDPI);
    }       
    
    //Exit stage right or left!
    return 0;
}

