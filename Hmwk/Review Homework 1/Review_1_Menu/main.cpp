/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Sept 6th, 2021, 3:34PM
 * Purpose:  Menu for Review Assignment
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>   //File Stream
#include <cstdlib>   //Srand
#include <ctime>     //Time library
#include <iomanip>   //Formatting Lbrary
#include <cmath>     //Math Library - Log Function
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables here
    int choose;//Choose a problem
    
    //Initialize variables here
    do{
        //Display the menu
        cout<<endl;
        cout<<"Choose from the following Menu Items"<<endl;
        cout<<"Problem 0 - Temp Conversion - Gaddis 9thEd Chap 3 Prob 12"<<endl;
        cout<<"Problem 1 - Currency Conversion - Gaddis 9thEd Chap 3 Prob 13"<<endl;
        cout<<"Problem 2 - Days in a Month - Gaddis 9thEd Chap4 Prob10"<<endl;
        cout<<"Problem 3 - Population - Gaddis 9thEd Chap5 Prob11"<<endl;
        cout<<"Problem 4 - Celsius Temp Table - Gaddis 9thEd Chap6 Prob7"<<endl;
        cout<<"Problem 5 - Rain or Shine - Gaddis 9thEd Chap7 Prob6"<<endl;
        cout<<"Problem 6 - String Search - Gaddis 9thEd Chap8 Prob7"<<endl;
        cout<<"10 or greater, all negatives to exit"<<endl;
        cout<<endl;
        cin>>choose;
        
        //Display the Solution to the problems
        switch(choose){
            case 0:{  
                //PROBLEM:
                //Write a program that converts Celsius temperatures to Fahrenheit 
                //temperatures. The formula is F = (9/5)(C) + 32.
                
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
               
                break;}
            
            case 1:{    
                //PROBLEM:
                //Write a program that will convert U.S. dollar amounts to 
                //Japanese yen and to euros, storing the conversion factors in 
                //the constants YEN_PER_DOLLAR and EUROS_PER_DOLLAR.
                
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
                break;}
            case 2:{
                //PROBLEM:
                //Write a program that asks the user to enter the month 
                //(letting the user enter an integer in the range of 1 through 12) 
                //and the year. The program should then display the number of days in that month.
                
                //Declare variables here
                unsigned short int month,year;
                
                //Initialize variables here
                cout << "Enter month (1 - 12): "; 
                cin >> month;
                cout << "Enter year: "; 
                cin >> year;

                //Display the results
                switch (month)
                {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    cout << "31 days";
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    cout << "30 days";
                    break;

            case 2:
                //Leap year
                if (year % 100 == 0)
                {
                    if (year % 400 == 0)
                        cout << "29 days" << endl;
                    else
                        cout << "28 days" << endl;
                }
                else if (year % 100 != 0)
                {
                    if (year % 4 == 0)
                        cout << "29 days" << endl;
                    else
                        cout << "28 days" << endl;
                }
                break;

            default:
                cout << "Invalid entry, please try again." << endl;
               }
                break;}
            
            case 3:{
                //PROBLEM:
                /* Write a program that will predict the size of a population of organisms. 
                 * The program should ask the user for the starting number of organisms, 
                 * their average daily population increase (as a percentage), and the number 
                 * of days they will multiply. A loop should display the size of the population for each day.
                 */
                
                //Declare variables here
                float sNumOrg,  //Starting number of organisms
                      avDPI,    //Average Daily Population Increase
                      sDPI;     //Size of Daily Population Increase

                unsigned short int numDTM;     //Number of days to multiply

                //Initialize variables here
                //Map inputs to outputs here, i.e. the process
                cout << "Enter the starting number of organisms: ";

                while (!(cin >> sNumOrg || sNumOrg < 2)) {
                    cout << "Starting number must be 2 or greater." << endl;
                    cout << "Enter the starting number of organisms: ";
                    cin.clear();
                    cin.ignore();
                }
                cout << "Enter average daily population increase (%):"<< endl;
                while (!(cin >> avDPI) || avDPI < 0) {
                    cout << "Average daily population increase\n"
                         << "must be greater than 0. Enter average\n"  
                         << "daily population increase (%): ";
                    cin.clear();
                    cin.ignore();
                }

                avDPI *= .01;
                cout << "Enter number of days they will multiply: ";

                while(!(cin >> numDTM) || numDTM < 1) {
                    cout << "Number of days must NOT be less than 1.\n"
                         << "Enter number of days they will multiply: \n";
                    cin.clear();
                    cin.ignore();
                }
                //Display the results
                for(int i = 0; i < numDTM; i++ ) {
                    cout << "Population size for day " << (i + 1);
                    cout << ": " << sNumOrg << endl;
                    sNumOrg += (sNumOrg * avDPI);
                }       
            break;}
            
            case 4: {
                //PROBLEM:
                /*Write a function named Celsius that accepts a Fahrenheit temperature 
                 *as an argument. The function should return the temperature, 
                 *converted to Celsius. Demonstrate the function by calling it 
                 *in a loop that displays a table of the Fahrenheit temperatures 
                 *0 through 20 and their Celsius equivalents.
                 */
                
                //Function Prototypes
                float celsius(int);
                
                //Declare variables here
                //Initialize variables here
                cout << "-----------------------------------|\n";
                cout << "Fahrenheit     | Celsius\n";
                cout << "-----------------------------------|\n";
                
                //Map inputs to outputs here, i.e. the process
                for (int F = 0; F <= 20; F++) {
		cout << "      " << setw(2) << F;
		cout << "          ";
                cout << setw(3) << celsius(F) << endl;
                }
                //Display the results
                
                break; }
            
            case 5: {
                
                //Constants
                const int numMnth=3;
                const int days=30;
                //Declare variables
                char wthr[numMnth][days];     //Weather
                int rnyDy=0,snyDy=0,cldDy=0,  //Rainy,Sunny,Cloudy Days
                    ttlRn=0, ttlSn=0, ttlCd=0,//Total Rainy,Sunny,Cloudy Days
                    lrgstRn=0;                //Largest rainy day
               
                //Initialize variables
                fstream RainOrShine;

                //Map inputs to outputs here, i.e. the process
                RainOrShine.open ("RainOrShine.txt");

                for(int month=0; month < numMnth; month++){
                    for(int day=0; day < days; day++){
                        RainOrShine >> wthr[month][day];
                    }
                }
                RainOrShine.close();
                cout<<"Three Month Summer Weather Report"<<endl;
                for(int month=0; month < numMnth ; month++){
                    rnyDy=0;
                    snyDy=0;
                    cldDy=0;
                    for(int day=0; day < days; day++){
                        switch (wthr[month][day]){
                            case 'S':snyDy++;
                            break;
                            case 'R':rnyDy++;
                            break;
                            case 'C':cldDy++;
                            break;
                        }
                }
                //Display the results
                cout << "Months of ";
                if (month == 0)
                    cout << "June" << endl;
                else if (month == 1)
                    cout << "July" << endl;
                else if (month == 2)
                    cout << "August" << endl;
                // Sum of rain sun and cloudy
                    cout << "Total Sunny Days = " << snyDy << endl;
                    cout << "Total Rainy Days = " << rnyDy << endl;
                    cout << "Total Cloudy Days = "<< cldDy<< endl;
                    ttlSn += snyDy;
                    ttlRn += rnyDy;
                    ttlCd += cldDy;

                    if(lrgstRn>rnyDy)
                        lrgstRn = month;
                }
                cout << "Over three months for:\n" << "Rainy\t Cloudy\t Sunny\t" << endl;
                cout << ttlRn << "\t" <<ttlCd<< "\t" << ttlSn << endl;

                cout<<"Most Rainiest Month is : ";
                if(lrgstRn==0)
                    cout << "June";
                else if (lrgstRn==1)
                    cout << "July";
                else if (lrgstRn==2)
                    cout << "August";
            break; }
            
            case 6: {
                //Function Prototypes
                void selSrt(string[], int);
                void swap(string &, string &);
                void prntAry(string[], int, string);
                int binSrch(string[], int, string);
                
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
                
            break;}
            
            default:cout<<"Exiting the Menu"<<endl;
        }
    }while(choose>=0 && choose<=6);

    return 0;
}

float celsius(int F)
{
	return (5.0 * (F - 32))/9;
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