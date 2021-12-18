/* 
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/18/21  8:00pm
    Gaddis 9th C13P4
Challenge 4:"Patient Charges"
Write a class named Patient that has member variables referred to in the text
*/

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
class Patient{
private:
string first, mid, last;        //First, middle, and last name
string add, city, state;        //Address
long    zip, num;               //Zip Code and Number
string  emerNam;                //Emergency Name
long    emerNum;                //Emergency Number
public:
Patient(string firstN, string midN, string lastN,
string add, string city, string state,
long zip, long number, string eName,long eNum){
this->first = firstN;
this->mid = midN;
this->last = lastN;
this->add = add;
this->city = city;
this->state = state;
this->zip = zip;
this->num = num;
this->emerNam = eName;
this->emerNum = eNum;
}
// Mutator
void setFirst(string firstN);
void setMid(string midN);
void setLast(string lastN);
void setAdd(string add);
void setCity(string city);
void setState(string state);
void setZIP(long zip);
void setNumber(long number);
void setEName(string eName);
void setENumber(long enumber);
  
// Accessor
string getFirst();
string getMid();
string getLast();
string getAdd();
string getCity();
string getState();
long getZIP();
long getNum();
string getEName();
long getENumber();
};

class Procedure{
private:
string name;
string date;
string pract;
double charge;
 
public:
Procedure(string name, string date, string pract, double charge){
this->name = name;
this->date = date;
this->pract = pract;
this->charge =charge;
}
  
// Mutator
void setName(string name);
void setDate(string date);
void setPract(string pract);
void setChrg(double chrg);

// Accessor
string getName();
string getDate();
string getPract();
double getChrg();
  
};
//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    
    //Initialize variables here
    Patient P("John", "smith", "williams", "123 ABC street", "Riverside", "California", 92553,6619461234, "Mom Smith", 6619441234);
    //Map inputs to outputs here, i.e. the process
    Procedure p1("Physical Exam", "Today's date", "Dr. Irvine", 250);
    Procedure p2("X-ray", "Today's date", "Dr. Jamison", 500);
    Procedure p3("Blood test", "Today's date", "Dr. Smith", 200);
    //Display the results
    cout <<"------------------------------"<<endl;
    cout << "Patient Information\n";
    cout <<"------------------------------"<<endl;
    cout << "Name: " << P.getFirst() << " " << P.getMid() << " " << P.getLast() << endl;
    cout << "Address: " << P.getAdd() << endl;
    cout << "City: " << P.getCity() << endl;
    cout << "State: " << P.getState() << endl;
    cout << "ZIP Code: " << P.getZIP() << endl;
    cout << "Phone Number: " << P.getNum() << endl;
    cout << "Emergency Contact Person: " << P.getEName() << endl;
    cout << "Emergency Contact Person's Number: " << P.getENumber() << endl;
    cout <<"------------------------------"<<endl;
    cout << "Procedures\n";
    cout <<"------------------------------"<<endl;
    cout << "\nProcedures #1"<<endl;
    cout << "Procedure Name: " << p1.getName() << endl;
    cout << "Date: " << p1.getDate() << endl;
    cout << "Practitioner: " << p1.getPract() << endl;
    cout << "Charge: " << fixed<< setprecision(2) << p1.getChrg() << endl;
    cout << "\nProcedures #2"<<endl;
    cout << "Procedure Name: " << p2.getName() << endl;
    cout << "Date: " << p2.getDate() << endl;
    cout << "Practitioner: " << p2.getPract() << endl;
    cout << "Charge: " << p2.getChrg() << endl;
    cout << "\nProcedures #3"<<endl;
    cout << "Procedure Name: " << p3.getName() << endl;
    cout << "Date: " << p3.getDate() << endl;
    cout << "Practitioner: " << p3.getPract() << endl;
    cout << "Charge: " << p3.getChrg() << endl;

    cout << "\nTotal Charges: " << p1.getChrg() + p2.getChrg() + p3.getChrg() << endl;
    return 0;
}
void Patient::setFirst(string firstN){
this->first = firstN;
}
void Patient::setMid(string midN){
this->mid = midN;
}
void Patient::setLast(string lastN){
this->last = lastN;
}
void Patient::setAdd(string add){
this->add = add;
}
void Patient::setCity(string city){
this->city = city;
}
void Patient::setState(string state){
this->state = state;
}
void Patient::setZIP(long zip){
this->zip = zip;
}
void Patient::setNumber(long num){
this->num = num;
}
void Patient::setEName(string emergencyName){
this->emerNam = emergencyName;
}
void Patient::setENumber(long number){
this->emerNum = emerNum;
}
// AC
string Patient::getFirst(){
return this->first;
}
string Patient::getMid(){
return this->mid;
}
string Patient::getLast(){
return this->last;
}
string Patient::getAdd(){
return this->add;
}
string Patient::getCity(){
return this->city;
}
string Patient::getState(){
return this->state;
}
long Patient::getZIP(){
return this->zip;
}
long Patient::getNum(){
return this->num;
}
string Patient::getEName(){
return this->emerNam;
}
long Patient::getENumber(){
return this->emerNum;
}
void Procedure::setName(string name){
this->name = name;
}
void Procedure::setDate(string date){
this->date = date;
}
void Procedure::setPract(string pract){
this->pract = pract;
}
void Procedure::setChrg(double charge){
this->charge = charge;
}
string Procedure::getName(){
return this->name;
}
string Procedure::getDate(){
return this->date;
}
string Procedure::getPract(){
return this->pract;
}
double Procedure::getChrg(){
return this->charge;
} 
