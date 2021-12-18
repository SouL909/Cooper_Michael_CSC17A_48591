/* 
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/19/21  10:00am
    Gaddis 9th C13P5
Challenge 5: "Retail Item Class"
Write a class named RetailItem that holds data about an item in a retail store.
*/

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
#include <iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
class RetailItem{
private:
string desc;
int units;
float price;
public:
RetailItem(string,int,float);
void setdesc(string);   //set description
void setunts(int);      //set units
void setprce(float);    //set price
string getdesc()const;  //get description
int getunts()const;     //get units
float getprce()const;   //get price
};
//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    RetailItem item1("Jacket",12,59.95);
    RetailItem item2("Designer Jeans",40,34.95);
    RetailItem item3("Shirt",20,24.95);

    //Display the results
    cout << "--------------------------------------------------------"<<endl;
    cout << setw(23)<<"Description "
         << setw(22)<<"Units On Hand"
         << setw(10)<<"Price"<<endl;
    cout << "--------------------------------------------------------"<<endl;
    cout << left << setw(12) << "item#1" << setw(20)<< item1.getdesc()
         << setw(18) << item1.getunts() << setw(15) << item1.getprce() << endl;
    
    cout << setw(12) << "item#2" << setw(20) << item2.getdesc()
         << setw(18) << item2.getunts() << setw(15) << item2.getprce() << endl;
    
    cout << setw(12) << "item#3" << setw(20) << item3.getdesc()
         << setw(18) << item3.getunts() << setw(15) << item3.getprce() << endl;
    return 0;
}
//default constructor
RetailItem::RetailItem(string newd,int newu,float newp){
    desc=newd;
    units=newu;
    price=newp;
}
void RetailItem::setdesc(string newd){
    desc=newd;
}
void RetailItem::setunts(int newu){
    units=newu;
}
void RetailItem::setprce(float newp){
    price=newp;
}
string RetailItem::getdesc()const{
    return desc;
}
int RetailItem::getunts()const{
    return units;
}
float RetailItem::getprce()const{
    return price;
}
