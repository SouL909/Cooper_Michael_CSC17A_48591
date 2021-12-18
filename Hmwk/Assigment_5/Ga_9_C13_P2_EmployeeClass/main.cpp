/* 
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/18/21  1:00pm
    Gaddis 9th C13P2
Challenge 2:"Employee Class"
Write a class named Employee that has the following member variables:
Name: a string that holds the employee's name
idNumber: a n int variable that holds the employee's ID number
Department: a string that holds the name of the department where the employee
works
position: a string that holds the employee's job title
The class should have the constructors mentioned in the text:
Programmer
Engineer
The program should store this data in the three objects and then display the data for
each employee on the screen.
 */

 //System Libraries
#include <iostream>   //Input/Output Library
#include <string>
#include <iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Employee.h"
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here

    //Declare variables here

    //Initialize variables here
    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee emp2("Mark Jones", 39119,"","");
    emp2.setDept("IT");
    emp2.setPost("Programmer");
    Employee emp3;
    emp3.setName("Joy Rogers");
    emp3.setIdNm(81774);
    emp3.setDept("Manufacturing");  //department
    emp3.setPost("Engineer");

    //Map inputs to outputs here, i.e. the process

    //Display the results
    cout << "----------------------------------------------------------" << endl;
    cout << left << setw(15) << "Name"      << setw(12)
         << "ID Number"      << setw(15)    << "Department"
         << setw(15)         << "Position"  << endl;
    cout << "----------------------------------------------------------" << endl;

    cout << setw(15) << emp1.getName()   << setw(12) << emp1.getIdNum()
         << setw(15) << emp1.getDept()   << setw(15) << emp1.getPost()
         << endl;
    cout << setw(15) << emp2.getName()   << setw(12) << emp2.getIdNum()
         << setw(15) << emp2.getDept()   << setw(15) << emp2.getPost()
         << endl;
    cout << setw(15) << emp3.getName()   << setw(12) << emp3.getIdNum()
         << setw(15) << emp3.getDept()   << setw(15) << emp3.getPost()
         << endl;
    cout << "----------------------------------------------------------" << endl;
    
    return 0;
}