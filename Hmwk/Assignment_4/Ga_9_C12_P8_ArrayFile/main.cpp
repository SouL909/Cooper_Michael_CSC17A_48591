/*
    Author: Michael Cooper
    Date:   10/16/21  6:00pm
    Gaddis 9th C12P8
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <fstream>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void arrayToFile(string,int*,int);
void fileToArray (string,int*, int);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    int size=10;
    string inputFile = "Test.dat";
    int arr1[]={1,2,3,4,5,6,7,8,9,10};
    int arr2[10];
    //Initialize variables
    
    //Process, map inputs to outputs
    
    //Display your initial conditions as well as outputs.
    arrayToFile(inputFile, arr1, size);
    fileToArray(inputFile, arr1, size);
    //Exit stage right
    return 0;
}
void arrayToFile(string filenme, int *arrPtr, int size){
    cout << "Input the numbers to be written to the file:" << endl;
    for(int i = 0; i < size; i++){
        cout << arrPtr[i] << " ";
        
        ofstream outfile;
        outfile.open(filenme.c_str(),ios::binary|ios::out);
        
        for (int i = 0; i < size; i++)
            outfile << arrPtr[i] << " ";
        
        outfile.close();
    }
}
void fileToArray (string filenme, int *arrPtr, int size){
    ifstream infile;
    infile.open(filenme.c_str(),ios::binary |ios::in);
    for (int i = 0; i < size; i++)
        infile >> arrPtr[i];
    cout << "\nThe numbers read from the file:" << endl;
    for(int i = 0; i < size; i++)
        cout << arrPtr[i] << " ";
    infile.close();
}
