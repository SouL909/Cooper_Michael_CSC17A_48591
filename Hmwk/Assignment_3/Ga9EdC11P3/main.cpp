/* 
 * Author: Michael Cooper
 * Created on  10/4/21
 * Purpose: Prob 1
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
struct sales{float first, second, third, fourth, annual, total, average;};
//Function Prototypes
void northSales (sales a);
void westSales (sales a);
void eastSales (sales a);
void southSales (sales a);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    
    //Initialize Variables
    
    //Process or map Inputs to Outputs
    sales distOne;
    cout << "North" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> distOne.first;
    cout << "Enter second-quarter sales:" << endl;
    cin >> distOne.second;
    cout << "Enter third-quarter sales:" << endl;
    cin >> distOne.third;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> distOne.fourth;
    
    northSales (distOne);
    
    sales distTwo;
    cout << "West" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> distTwo.first;
    cout << "Enter second-quarter sales:" << endl;
    cin >> distTwo.second;
    cout << "Enter third-quarter sales:" << endl;
    cin >> distTwo.third;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> distTwo.fourth;
    
    westSales (distTwo);
    
    sales distThree;
    cout << "East" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> distThree.first;
    cout << "Enter second-quarter sales:" << endl;
    cin >> distThree.second;
    cout << "Enter third-quarter sales:" << endl;
    cin >> distThree.third;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> distThree.fourth;
    
    eastSales (distThree);
    
    sales distFour;
    cout << "South" << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> distFour.first;
    cout << "Enter second-quarter sales:" << endl;
    cin >> distFour.second;
    cout << "Enter third-quarter sales:" << endl;
    cin >> distFour.third;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> distFour.fourth;
    
    southSales (distFour);
    
    //Display Outputs

    //Exit stage right!
    return 0;
}

void northSales (sales a) {
    a.total+=a.first+a.second+a.third+a.fourth;
    a.average=a.total/4;
    cout << fixed << setprecision(2) << showpoint;
    cout << "Total Annual sales:$" << a.total << endl;
    cout << "Average Quarterly Sales:$" << a.average << endl;
    
}


void westSales (sales a) {
    a.total+=a.first+a.second+a.third+a.fourth;
    a.average=a.total/4;
    cout << fixed << setprecision(2) << showpoint;
    cout << "Total Annual sales:$" << a.total << endl;
    cout << "Average Quarterly Sales:$" << a.average << endl;
}

void eastSales (sales a) {
    a.total+=a.first+a.second+a.third+a.fourth;
    a.average=a.total/4;
    cout << fixed << setprecision(2) << showpoint;
    cout << "Total Annual sales:$" << a.total << endl;
    cout << "Average Quarterly Sales:$" << a.average << endl;
}

void southSales (sales a) {
    a.total+=a.first+a.second+a.third+a.fourth;
    a.average=a.total/4;
    cout << fixed << setprecision(2) << showpoint;
    cout << "Total Annual sales:$" << a.total << endl;
    cout << "Average Quarterly Sales:$" << a.average;
}