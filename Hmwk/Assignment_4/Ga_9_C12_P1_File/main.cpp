/*
    Author: Michael Cooper
    Date:   10/15/21  11:00am
    Gaddis 9th C12P1
 Challenge 1:"Write a program that asks the user for the name of a file"
 The program should display the first ten lines of the files on the screen
 If fewer than 10 lines, the entire files should be displayed, with a message
 indicating the entire file has been displayed.
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    string name;
    char line[80];
    fstream infile;
    int counter;
    
    //Initialize variables
    counter = 1;
    
    //Process, map inputs to outputs
    cout << "Enter file name:";
    cin  >> name;
    
    //Display your initial conditions as well as outputs.
    infile.open(name,ios::in);
    while(!infile.eof() && counter <= 10){
        infile.getline(line,81,'\n');
        cout << line << endl;
        counter++;
    }
    if (counter < 10){
        cout<<"The entire file has been displayed";
    }
    //Exit stage right
    return 0;
}

