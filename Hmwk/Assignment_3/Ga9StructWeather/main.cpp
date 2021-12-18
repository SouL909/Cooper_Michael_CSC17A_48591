/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on 10/9/21, 2021, 11:00 AM
 * Purpose: HW 3 Prob 5
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
      MONTHS months;
};

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

    low.lowTemp=100;
    high.highTemp=-140;

    for (int i = 0; i <= 11; i++) {
        weather w;
        string month_name;
        cin>>month_name>>w.rain>>w.lowTemp>>w.highTemp;
        w.months = string_to_month(month_name);
        if (w.lowTemp< low.lowTemp){
            low=w;
        }
        if (w.highTemp>high.highTemp){
            high=w;
        }
        average_rainfall+=w.rain;
        temperature+=w.lowTemp+w.highTemp;

    }
    average_rainfall/=12.0;
    temperature/=24.0;
    //Initialize variables

    //Process, map inputs to outputs
        cout<<fixed<<setprecision(1)<<showpoint;
        cout<<"Average Rainfall "<<average_rainfall<<" inches/month"<<endl;
        cout<<"Lowest  Temperature "<<displayMonth(low.months)<<"  "<<static_cast<int>(low.lowTemp)<<" Degrees Fahrenheit"<<endl;
        cout<<"Highest Temperature "<<displayMonth(high.months)<<"  "<<static_cast<int>(high.highTemp)<<" Degrees Fahrenheit"<<endl;
        cout<<"Average Temperature for the year "<<static_cast<int>(rint(temperature))<<" Degrees Fahrenheit"<<endl;
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