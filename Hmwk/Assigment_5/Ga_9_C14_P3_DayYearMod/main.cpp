/*
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/20/21  9:00am
    Gaddis 9th C14P3
Challenge 3: "Day of the Year Modification"
 */

//System Libraries
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
class DayOfYear{        
private:
int year;
int day;
string month;
int count=0;
public:
DayOfYear& operator ++();
DayOfYear& operator --();
public:
DayOfYear(char month[], int day);
   public:
   string month_names(int month_number);  
   public:
   int month_days(int month_number);
};         
//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
   char month[12];
   int day;
   
    //Initialize variables here
   
    //Map inputs to outputs here, i.e. the process
    
    //Display the results
   cout << "Day of The Year Modification" << endl;
   cout << "Enter Month of Year:" << endl;
   cin  >> month;
   cout << "Enter Day Of The Month" << endl;
   cin  >> day;
   DayOfYear obj(month,day);
   return 0;
   
} 

DayOfYear::DayOfYear(char month[], int day){      
       for(int i=0;i<12;i++){
           if(month_names(i) == month){
               if( day > 0 && day <= month_days(i)){
                   this->month = month;
                   this->day = day;
                   year = 0;
                   for(int j=0;j < count; j++){
                       year = year+ month_days(j);
                   }  
                   year = year+day;
                   cout << "The Day Of The Year is:" << year << endl;
               }
               else{
                   cout << "Invalid Entry" << endl;
                   exit(0);
               }  
              
           }
           count++;
       }   
   }      
string DayOfYear::month_names(int month_number)
   {
       string month_names[] ={"January","February","March","April", "May","June","July","August","September","October","November","December"};
       return month_names[month_number];
   }   
int DayOfYear::month_days(int month_number)
   {
       int month_days[]={31,28,31,30,31,30,31,31,30,31,30,31};
       return month_days[month_number];
   } 
