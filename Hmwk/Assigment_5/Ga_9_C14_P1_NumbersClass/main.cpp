/* 
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/19/21  10:00am
    Gaddis 9th C14P1
Challenge 1: "Numbers Class"
Write a class named Numbers that can be used to translate whole dollar amounts.
*/

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
#include <math.h>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
class Numbers{
private:
    int num;
public:
    Numbers(int);
    void print();
};
//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int n;
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
    cout << "Enter a number starting from 1-9999."<<endl;
    cout << "To exit the program input 0."<<endl;
    cout << "Enter a Number: ";
    cin  >> n;
    while(n != 0) {
        cout << "The Number Converted is: ";
        Numbers number(n);
        number.print();
        cout << "\nEnter a Number: ";
        cin >> n;
    }
    return 0;
}
Numbers::Numbers(int x){
    num = x;
}
void Numbers::print(){
    int n;
    string less[20] = {"Zero","one","two","three","four","five",
                     "six","seven","eight","nine","ten","eleven",
                     "twelve","thirteen","fourteen","fifteen","sixteen",
                     "seventeen","eighteen","nineteen"};
    string hundred = " hundred ";
    string thousand = " thousand ";
    string ten[] = {"zero","ten","twenty","thirty","forty","fifty",
                  "sixty","seventy","eighty","ninety"};
    if(num < 0)
        cout << "ERROR: Must Enter a Number Greater Than 0.";
    num = abs(num);
    n = num/1000;
    if(n > 0)
        cout << " " << less[n] << thousand;
    num %= 1000;
    n = num/100;
    if(n > 0)
        cout << less[n] << hundred;
    num %= 100;
    if(num >= 20){
        n = num/10;
        cout << ten[n] << " ";
    }
    else if(num >= 10){
        cout << less[num] << " ";
        return;
    }
    num %= 10;
    if(num > 0)
        cout << less[num] << " ";
}