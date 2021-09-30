/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on Sept 6, 2021, 12:36 PM
 * Purpose:  Chap 7 Prob 6 (Rain or Shine)
 * 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <fstream>
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
    
    //Exit stage right or left!
    return 0;
}


