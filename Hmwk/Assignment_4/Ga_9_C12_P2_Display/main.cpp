/*
    Author: Michael Cooper
    Date:   10/15/21  4:00pm
    Gaddis 9th C12P2
 Challenge 2: Write a program that asks the user for the name of a file
 The program should display the contents of the files on the screen.
 If the files contents wont fit on a single screen, 24 lines should be shown
 followed by a pause. The program should display the next 24 lines after
 the user strikes a key.
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <fstream>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    char name[11],
         line[80],
               ch;
    int   count=0;
    fstream fileIn;
    
    //Initialize variables
    
    //Process, map inputs to outputs
    cout << "Enter the name of your file:";
    cin.getline(name,11);
    fileIn.open(name,ios::in);
    fileIn.get(ch);
    
    //Display your initial conditions as well as outputs.
    while(fileIn){
        if(ch == '\n')
            count++;
            fileIn.get(ch);
    }
    if(count < 10){
        cout << "The entire file has been displayed" << endl;
    }
    fileIn.close();
    fileIn.open(name, ios::in);
    fileIn.get(ch);
    while(fileIn){
        if (ch == '\n'){
            count--;
        }
        if (count <= 10)
            while(fileIn){
                cout << ch;
                fileIn.get(ch);
            }
        fileIn.get(ch);
    }
    fileIn.close();
    //Exit stage right
    return 0;
}
