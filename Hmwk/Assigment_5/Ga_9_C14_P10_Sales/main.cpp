/* 
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/21/21  10:00am
    Gaddis 9th C14P10
Challenge 10: "Corporate Sales"
*/
//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
class DivSales
{
private:
    static int Year_Sales;//total sale
    int Qtrsale[4];       //quarter sale figures

public:
    void AddSales (int sale1, int sale2, int sale3, int sale4);
    int Sales(int n);
    int getvalue(){
        return Year_Sales;
    }
};
//Function Prototypes
//void AddSales(int sale1, int sale2, int sale3, int sale4);
//int Sales(int n);
void error();
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int quart, 
        div;
    const int DS = 6;
    DivSales DivSale[DS]; 
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    for (div = 0; div < 6; div++){
        int Q1, Q2, Q3, Q4;
        int Q;           //check for negative input
        cout << "Enter Sales of Division: " << div + 1 << endl;
        cout << "Enter Q1 Sales: ";
        cin >> Q1;
        Q = Q1;
        if (Q < 0)
            error();
        cout << "Enter Q2 Sales: ";
        cin >> Q2;
        Q = Q2;
        if (Q < 0)
        error();

        cout << "Enter Q3 Sales: ";
        cin >> Q3;
        Q = Q3;
        if (Q < 0)
        error();

        cout << "Enter Q4 Sales: ";
        cin >> Q4;
        Q = Q4;
        if (Q < 0)
        error();
        DivSale[div].AddSales(Q1,Q2,Q3,Q4);
    }

cout << "\n----------------------------------------\n";
cout << "\t" << "Q1" << "\t" << "Q2" << "\t" << "Q3" << "\t" << "Q4" << endl;

// table for quarterly sales of each division
for (div = 0; div < 6; div++){
    cout << "Div " << div + 1;
    for (quart = 0; quart < 4; quart++){
        cout << "\t$" << DivSale[div].Sales(quart);
    }
    cout << endl;
}

cout << "----------------------------------------\n";
cout << "\nTotal corporate sales for the year: ";
cout << "$" << DivSale[0].getvalue() << endl;
    //Display the results

    return 0;
}

int DivSales::Year_Sales = 0;
void DivSales::AddSales(int sale1, int sale2, int sale3, int sale4){
    Qtrsale[0] = sale1;
    Qtrsale[1] = sale2;
    Qtrsale[2] = sale3;
    Qtrsale[3] = sale4;
    Year_Sales = Year_Sales + sale1 + sale2 + sale3 + sale4;
}

int DivSales::Sales(int n){
    int value = Qtrsale[n];
    return value;
}

void error(){
    cout << "You have entered a negative value. Restart program and try again";
    cout << "Press any key to restart program\n";

}

