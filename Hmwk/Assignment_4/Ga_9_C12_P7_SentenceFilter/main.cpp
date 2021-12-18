/*
    Author: Michael Cooper
    Date:   10/16/21  12:00pm
    Gaddis 9th C12P7
 
 Challenge 7: Write a program that asks the user for two file names.
 The first file will be opened for input and the second for output. The program
 will read the contents of the first file, change all letters to lowercase
 (except the first letter of each sentence, which will be made uppercase). The
 revised contents should be stored in the second file. 
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <fstream>     //File Input/Output Library
#include <string>      //String Library
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
void capitalize(char *, bool &);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare variables
    const int SIZE = 81;      //Array size
    ifstream inpFile;         //Input file
    ofstream outFile;         //Output file
    string inpName;           //Input file name
    string outName;           //Output file name
    char inpLine[SIZE];       //Line of Input
    bool midSentence = false; //Flag, init. false
    
    //Initialize variables
    bool midSent = false;
    
    //Process, map inputs to outputs
    //Get name of input file
    cout << "Enter the name of your input file(infile.txt): ";
    getline(cin, inpName);
    inpFile.open(inpName);
 
    cout << "Enter the output file name(outfile.txt): ";
    getline(cin, outName);
    
    //Open output file
    outFile.open(outName);
    
    //Read and process the input file
    while(!inpFile.eof()){
        char *ptr;
        inpFile.getline(inpLine, 81, '\n');

        capitalize(inpLine, midSentence); //Capitalize
        cout << inpLine << endl;
        ptr = inpLine;

        //Write the string to outFile
        while (*ptr != 0){
            outFile.put(*ptr);
            ptr++;
        }
    }
    // Close the files.
    inpFile.close();
    outFile.close();
    
    //Exit stage right
    return 0;
}

// Function capitalize
void capitalize(char *str, bool &midSentence){
    bool period; // Flag
    if(midSentence)period = false;
    else
        period = true;
    while(*str != 0){
        while(*str != 0 && isspace(*str))str++;
        
        if(period && *str != 0){
            *str = toupper(*str);
            period = false;
            str++;
            }

            while(*str != 0 && !isspace(*str) && *str != '.'){
                *str = tolower(*str);
                str++;
            }

            if(*str == '.'){
                period = true;
                str++;
                break;
            }
    }
    if(period)midSentence = false;
    else
        midSentence = true;
}
