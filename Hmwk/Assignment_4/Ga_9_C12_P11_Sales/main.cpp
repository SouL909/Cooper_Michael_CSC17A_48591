/*
    Author: Michael Cooper
    Date:   10/17/21  5:00pm
    Gaddis 9th C12P11
 
 Challenge 11: Write a program that uses a structure to store data on a company
 division.
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;
//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only
struct sales{
    vector<float>quart;
};
//Function Prototypes
void dataToFile(sales *sales);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    
    //Initialize variables
    sales sales[4];
    string dist[4] = {"North","West","East","South"};
    //Process, map inputs to outputs
    for(int i = 0; i < 4; i++){ 
        cout<<dist[i];
        cout<<"\n";
        cout<<"Enter first quarter sales:"<<endl;
        cout<<"Enter second quarter sales:"<<endl;
        cout<<"Enter third quarter sales:"<<endl;
        cout<<"Enter fourth quarter sales:"<<endl;
        
        float quart,
              quart2,
              quart3,
              quart4;
        
        bool valInput = true;
        do{ 
            if(!valInput){
                cout << "Must put in a value greater than 0" << endl;
            }
            valInput = true;
            cin >> quart >> quart2 >> quart3 >> quart4;
            if (quart < 0){
                valInput = false;
            }
            if (quart2 < 0)
                valInput = false;
            if (quart3 < 0){
                valInput = false;
            }
            if (quart4 < 0)
                valInput = false;
            
        }while(!valInput);
        
        sales[i].quart.push_back(quart);
        sales[i].quart.push_back(quart2);
        sales[i].quart.push_back(quart3);
        sales[i].quart.push_back(quart4);
    
 }
    dataToFile(sales);
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
return 0;
}
void dataToFile(sales* sales){
    
    ofstream salesdata("sales.txt",std::ofstream::out | std::ofstream::in);
    salesdata << fixed << setprecision(2) << showpoint;
    
    salesdata << "North Quarterly sales:" << endl;
    salesdata << sales[0].quart[0] << " " 
              << sales[0].quart[1] << " " 
              << sales[0].quart[2] << " " 
              << sales[0].quart[3];
    
    salesdata <<"\nWest Quarterly sales:"<<endl;
    salesdata << sales[1].quart[0] << " " 
              << sales[1].quart[1] << " " 
              << sales[1].quart[2] << " " 
              << sales[1].quart[3];
    
    salesdata << "\nEast Quarterly sales:" << endl;
    salesdata << sales[2].quart[0] << " "
              << sales[2].quart[1] << " "
              << sales[2].quart[2] << " " 
              << sales[2].quart[3];
    
    salesdata << "\nSouth Quarterly sales:" << endl;
    salesdata << sales[3].quart[0] << " "
              << sales[3].quart[1] << " "
              << sales[3].quart[2] << " "
               <<sales[3].quart[3];
    salesdata.close();
}
