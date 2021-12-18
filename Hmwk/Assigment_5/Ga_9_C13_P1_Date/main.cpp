/* 
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/15/21  11:00am
    Gaddis 9th C13P1
Challenge 1:"Date"
Design a class called Date. The class should store a date in three integers: month, day,
and year. There should be member functions to print the date in the following forms:
12/25/2018
December 25, 2018
25 December 2018
Demonstrate the class by writing a complete program implementing it.
Input Validation: Do not accept values for the day greater than 31 or less than 1. Do
not accept values for the month greater than 12 or less than 1.
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
class Date{
private:
    int day;
    int months;
    int year;
public:
    Date();
    Date(int tmonth, int tday, int tyear);
    int getMnth();
    int getDay();
    int getYear();
    void setMnth(int tmonth);
    void setDay(int tday);
    void setYear(int tyear);
    void datDsp();      //Data Display 1
    void datDsp2();     //Data Display 2
    void datDsp3();     //Data Display 3
    string gmonth();    //Get Month String
};
//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
  
    //Declare variables here
    int month, day, year;

    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    cout << "Enter Month: ";     //month(1-12)
    cin >> month;

    while (month < 1 || month > 12){
       cout << "Invalid Entry. Please Enter Month (1-12): ";
       cin >> month;
   }

    cout << "\nEnter the day: ";     //valid day(1-31)
    cin >> day;

    while (day < 1 || day > 31){
       cout << "Invalid Entry. Please Enter Day (1-31): ";
       cin >> day;
   }

   
   cout << "\nEnter the year: ";     //valid year
   cin >> year;

   while (year < 1){
       cout << "Invalid Entry. \n Please Enter Year (>1): ";
       cin >> year;
   }

   Date date(month, day, year);
   //Display the results
   cout << "\nYour date:" << endl;  //different formats
   date.datDsp();
   date.datDsp2();
   date.datDsp3();
   cout<<endl;
    return 0;
}

Date::Date(){
   setMnth(1);
   setDay(1);
   setYear(2000);
}
Date::Date(int tmonth, int tday, int tyear){
   setMnth(tmonth);
   setDay(tday);
   setYear(tyear);
}
//default val
void Date::setMnth(int tmonth){
   if (tmonth < 1 || tmonth > 12){
       cout << tmonth;
       months = 1;
   }
   else{
       months = tmonth;
   }
}
void Date::setDay(int tday){
   if (tday < 1 || tday > 31){
       cout << tday;
       day = 1;
   }
   else{
       day = tday;
   }
}
void Date::setYear(int tyear){
   if (tyear < 1){
       cout << tyear;
       year = 2000;
   }
   else{
       year = tyear;
   }
}
int Date::getMnth(){
   return months;
}

int Date::getDay(){
   return day;
}

int Date::getYear(){
   return year;
}

// getting month from value
string Date::gmonth(){
   if (months == 1)
       return "January";  
   else if (months == 2)
       return "February";
   else if (months == 3)
       return "March";
   else if (months == 4)
       return "April";
   else if (months == 5)
       return "May";
   else if (months == 6)
       return "June";
   else if (months == 7)
       return "July";
   else if (months == 8)
       return "August";
   else if (months == 9)
       return "September";
   else if (months == 10)
       return "October";
   else if (months == 11)
       return "November";
   else if (months == 12)
       return "December";
}
// format function
void Date::datDsp(){
   if (months < 10)
       cout << "0";

   cout << months << "/";

   if (day < 10)
       cout << "0";

   cout << day << "/";

   if (year < 1000)
       cout << "0";

   if (year < 100)
       cout << "0";

   if (year < 10)
       cout << "0";

   cout << year << endl;
}

// printing functions
void Date::datDsp2(){
   cout << gmonth() << " " << day << ", " << year << endl;
}

// printing functions format
void Date::datDsp3()
{
   cout << day << " " << gmonth() << " " << year << endl;
}
