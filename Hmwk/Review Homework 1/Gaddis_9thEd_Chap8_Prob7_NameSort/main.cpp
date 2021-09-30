/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on September 6, 2021, 2:50 PM
 * Purpose:  Chap 8 Prob 7 (Binary Name Sort)
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
void selSrt(string[], int);
void swap(string &, string &);
void prntAry(string[], int, string);
int binSrch(string[], int, string);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    
    //Declare variables here
    const int NUM_NAMES = 20;   //Number of Names
    
    //Initialize variables here
    string inNme;   //Inputted name
    string names[NUM_NAMES] = 
    {"Collins, Bill", "Smith, Bart", "Allen, Jim", "Griffin, Jim",
    "Stamey, Marty", "Rose, Geri", "Taylor, Terri", "Johnson, Jill", 
    "Allison, Jeff", "Looney, Joe", "Wolfe, Bill", "James, Jean", 
    "Weaver, Jim", "Pore, Bob", "Rutherford, Greg", "Javens, Renee", 
    "Harrison, Rose", "Setzer, Cathy", "Pike, Gordon", "Holland, Beth" };

    //Map inputs to outputs here, i.e. the process
    prntAry(names, NUM_NAMES, "UNSORTED: \n--------------------");
    selSrt(names, NUM_NAMES);
    prntAry(names, NUM_NAMES, "SORTED: \n-------------------- ");

    cout << "Choose a name: " << endl;
    cin.ignore();
    getline(cin, inNme);

    //Display the results
    int position = binSrch(names, NUM_NAMES, inNme);

    if (position != -1)
       cout << names[position] << " was found." << endl;
    else
        cout << inNme << " was NOT found." << endl;
    //Exit stage right or left!
    return 0;
}
void selSrt(string a[], int SIZE)
{
    int min_index;
    string min_value;

    for (int start_index = 0; start_index < (SIZE - 1); start_index++)
    {
        min_index = start_index;
        min_value = a[start_index];

        for (int index = start_index + 1; index < SIZE; index++)
        {
            if (a[index] < min_value)
            {
                min_value = a[index];
                min_index = index;
            }
        }
        swap(a[min_index], a[start_index]);
    }
}

void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

void prntAry(string a[], int SIZE, string prompt)
{
    cout << prompt << endl;
    for (int i = 0; i < SIZE; i++)
        cout << a[i] << endl;
    cout << endl;
}

int binSrch(string a[], int size, string user_name)
{
    int first = 0,
        last = size - 1,  // 19
        middle,
        position = -1;
    bool found = false;

    while (!found && first <= last)
    {
        middle = (first + last) / 2; // (0 + 19) / 2 = 8

        if (a[middle] == user_name)     // Middle
        {
            position = middle;
            found = true;
        }
        else if (a[middle] > user_name)   // Lower Half
            last = middle - 1; // 8 - 1 = 7  // 8, 4, 4, 3, 2, 3, 
        else                                  // Upper Half
            first = middle + 1;  // 8 + 1 = 9
        
    }
    return position;
}
