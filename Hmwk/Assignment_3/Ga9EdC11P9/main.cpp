/*
    Author: Michael Cooper
    Date:   10/10/21
    Purpose: HW 3 gaddis 11.9
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <string>
#include <iomanip>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only
struct speakersB{
    string name,
          topic;
    float pNum,
          fee;
};
//Function Prototypes
void Display(speakersB [],int);
void data();
//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed

    //Declare variables

    //Initialize variables
    speakersB speakers[10];
    int choice;
    int i = 0;
    int size = 0;
    //Process, map inputs to outputs
    do{
        cout <<setw(20)<<"MENU"<<endl;
        cout <<"- - - - - - - - - - - - - - - - - - - -" << endl;
        cout << "Input A Number 1-4 To Utilize The Menu" << endl;
        cout << "1.Enter Data Into The Array"<<endl;
        cout << "2.Modify Data" << endl;
        cout << "3.Display Data" << endl;
        cout << "4.Exit" << endl;
        cout << "Enter Number:";
        cin  >> choice;
        switch(choice){
            case 1: cout << "Enter Speaker Name: ";
                    cin  >> speakers[i].name;
                    cout << "\nEnter Telephone Number: ";
                    cin  >> speakers[i].pNum;
                    cout << "\nEnter The Topic: ";
                    cin  >> speakers[i].topic;
                    cout << "\nEnter Required Fee: ";
                    cin  >> speakers[i].fee;
                    if (speakers[i].fee<0){
                        cout << "Fee Must Be Greater Than 0\n";
                        cout << "\nEnter Required Fee: ";
                        cin  >> speakers[i].fee;
                    }i++;
                    break;
            case 2: int element;
                    cout << "Enter element to be modified:";
                    cin  >> element;
                    cout << "Enter Speaker Name: ";
                    cin  >> speakers[element-1].name;
                    cout << "\nEnter Telephone Number: ";
                    cin  >> speakers[element-1].pNum;
                    cout << "\nEnter The Topic: ";
                    cin  >> speakers[element-1].topic;
                    cout << "\nEnter Required Fee: ";
                    cin  >> speakers[element-1].fee;
                    if(speakers[element-1].fee<0){
                        cout << "Fee Must Be Greater Than 0";
                        cout << "\nEnter Required Fee: ";
                        cin  >> speakers[element-1].fee;
                    }
                    break;
            case 3: Display(speakers,i);
                    break;
            case 4: exit(0);
                    break;
        }
    }
    while (choice!=4);
    system ("pause");

    //Display your initial conditions as well as outputs.

    //Exit stage right
    return 0;
}

void Display(speakersB sp[],int s){
        for(int i=0;i<s;i++){
            cout << "Customer Name: " << sp[i].name << endl;
            cout << "Enter The Topic: " << sp[i].pNum << endl;
            cout << "Enter Fee Required: " << sp[i].fee << endl;
        }
    }