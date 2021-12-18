/* 
 * File:   main.cpp
 * Author: Michael Cooper
 * Created on 10/10/21, 2021, 9:00 PM
 * Purpose: HW 4
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <string>
#include <iomanip>
#include <vector>
using namespace std;   //Library Name-space

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

struct sodas{
    string name;
    int price,
         quant;
};

//Function Prototypes
void displayMachine(vector<sodas>machine);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed

    //Declare variables

    //Initialize variables
    vector<sodas>machine;
    machine.push_back(sodas{"Cola       ", 75,20});
    machine.push_back(sodas{"Root Beer  ", 75,20});
    machine.push_back(sodas{"Lemon-Lime ", 75,20});
    machine.push_back(sodas{"Grape Soda ", 80,20});
    machine.push_back(sodas{"Cream Soda ", 80,20});

    int total=0;
    //Process, map inputs to outputs

    while(true){
        displayMachine(machine);

        string sodaNm;
        int money;


        getline(cin,sodaNm);

        if(sodaNm == "Quit")
        break;

        string s_money;
        getline(cin, s_money);
        money=stoi(s_money);

        int cost = 0;
        int index = -1;
        for(int i =0; i < machine.size(); i++){
            if(machine[i].name.substr(0,sodaNm.size())==(sodaNm)){
                cost = machine[i].price;
                if (money>cost){
                    machine[i].quant--;
                    money=money-cost;
                    total+=cost;
                    break;
                }
            }
        }
        cout<<money<<endl;
    }
    cout<<total<<endl;

    //Display your initial conditions as well as outputs.

    //Exit stage right
    return 0;
}
void displayMachine(vector<sodas>machine){
    for(int i = 0; i < machine.size();i++){
        cout << machine[i].name << machine[i].price << "  " << machine[i].quant << endl;
    }
    cout << "Quit" << endl;
}