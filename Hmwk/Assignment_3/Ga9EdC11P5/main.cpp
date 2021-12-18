/* 
 * Author: Michael Cooper
 * Created on 10/11/21
 * Purpose: Prob 2
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only
enum MONTHS {JANURARY, FEBUARAY, MARCH, APRIL, MAY, JUNE, JULY, 
             AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER};

struct weather {
    float rain,
        highTemp,
        lowTemp;
    MONTHS months;};

//Function Prototypes
string displayMonth(MONTHS);
MONTHS string_to_month(string);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed

    //Declare variables
    MONTHS User;
    weather low;
    weather high;
    float average_rainfall,
          temperature;

    low.lowTemp = 100;
    high.highTemp = -100;
    weather weathers[6];
    for (int i = JANURARY; i <= MAY+1; static_cast<MONTHS>(i++)){
        weathers[i].months = static_cast<MONTHS>(i);
        cout << "Enter the total rainfall for the month:" << endl;
        cout << "Enter the high temp:" << endl;
        cout << "Enter the low temp:" << endl;
        cin  >> weathers[i].rain>>weathers[i].highTemp>>weathers[i].lowTemp;

        weathers[i].months = static_cast<MONTHS>(i);
        if (weathers[i].lowTemp< low.lowTemp){
            low=weathers[i];
        }
        if (weathers[i].highTemp>high.highTemp){
            high = weathers[i];
        }
        average_rainfall += weathers[i].rain;
        temperature+=weathers[i].lowTemp+weathers[i].highTemp;

    }
    average_rainfall/=6.0;
    temperature/=12.0;
    //Initialize variables

    //Process, map inputs to outputs
        cout << fixed<<setprecision(2)<<showpoint;
        cout << "Average monthly rainfall:" << average_rainfall << endl;
        cout << "High Temp:"<<static_cast<int>(high.highTemp) << endl;
        cout << fixed<<setprecision(1) << showpoint;
        cout << "Low Temp:"<<static_cast<int>(low.lowTemp) << endl;
        cout << "Average Temp:" << temperature;
    //Display your initial conditions as well as outputs.

    //Exit stage right
    return 0;
}

string displayMonth(MONTHS month) {
    switch(month){
        case MONTHS::JANURARY:
        return "January";
        break;
        case MONTHS::FEBUARAY:
        return "February";
        break;
        case MONTHS::MARCH:
        return "March";
        break;
        case MONTHS::APRIL:
        return "April";
        break;
        case MONTHS::MAY:
        return "May";
        break;
        case MONTHS::JUNE:
        return "June";
        break;
        case MONTHS::JULY:
        return "July";
        break;
        case MONTHS::AUGUST:
        return "August";
        break;
        case MONTHS::SEPTEMBER:
        return "September";
        break;
        case MONTHS::OCTOBER:
        return "October";
        break;
        case MONTHS::NOVEMBER:
        return "November";
        break;
        case MONTHS::DECEMBER:
        return "December";
        break;
    }

}
MONTHS string_to_month(string month){
    if (month == "January")
    return MONTHS::JANURARY;
    else if (month == "February")
    return MONTHS::FEBUARAY;
    else if (month == "March")
    return MONTHS::MARCH;
    else if (month == "April")
    return MONTHS::APRIL;
    else if (month == "May")
    return MONTHS::MAY;
    else if (month == "June")
    return MONTHS::JUNE;
    else if (month == "July")
    return MONTHS::JULY;
    else if (month == "August")
    return MONTHS::AUGUST;
    else if (month == "September")
    return MONTHS::SEPTEMBER;
    else if (month == "October")
    return MONTHS::OCTOBER;
    else if (month == "November")
    return MONTHS::NOVEMBER;
    else  if(month == "December")
    return MONTHS::DECEMBER;

}