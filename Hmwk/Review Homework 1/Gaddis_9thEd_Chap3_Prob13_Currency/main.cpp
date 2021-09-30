/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Sept 4, 2021, 2:45 PM
 * Purpose:  Chap 3 Prob 12 (Currency Conversion)
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
    //Write a program that will convert U.S. dollar amounts to 
    //Japanese yen and to euros, storing the conversion factors in 
    //the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR.
    
    //Set the random number seed
    
    //Constants
    const float YEN_PER_DOLLAR = 109.83,
                EUROS_PER_DOLLAR = .84;

    //Declare Variables
    float entAmt, dty, dte; //entered amount, dollar to yen & euro.

    //Initialize variables here
    cout<<"Please Enter Amount in U.S Dollars:"<<endl;
    cin>>entAmt;

    //Map inputs to outputs here, i.e. the process
    //Currency Conversion
    dty = entAmt * YEN_PER_DOLLAR;
    dte = entAmt * EUROS_PER_DOLLAR;
    //Output
    cout<<setprecision(2)<<fixed<<endl;
    cout << "Amount in U.S Dollars = $"  << entAmt;                       
    cout << "\nAmount in Japanese Yen = ¥" << dty;
    cout << "\nAmount in Euro = €" << dte << endl;
    
    return 0;
}
