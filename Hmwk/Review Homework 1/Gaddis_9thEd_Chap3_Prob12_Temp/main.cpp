/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Sept 4, 2021, 12:36 PM
 * Purpose:  Chap 3 Prob 12 (Temp)
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
    //Set the random number seed
    
    //Declare Variables
    float fhrt, //Fahrenheit
          clsus; //Celsius
          
    //Initialize or input i.e. set variable values
    cout<<"Temperature Converter"<< endl;
    cout<<"Input Degrees Fahrenheit"<< endl;
    cin>>fhrt;
    //Map inputs -> outputs
    clsus = (5.0/9.0)*(fhrt-32.0);
    //Display the outputs
    cout<<setprecision(1)<<fixed<<fhrt<<" Degrees Fahrenheit = "<<clsus<<" Degrees Centigrade";
    
    //Exit stage right or left!
    return 0;
}


