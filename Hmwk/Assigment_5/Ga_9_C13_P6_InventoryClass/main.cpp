/* 
 * File:   main.cpp
    Author: Michael Cooper
    Date:   10/20/21  10:00am
    Gaddis 9th C13P6
Challenge 6: "Inventory Class"
*/

//System Libraries
#include <iostream>   //Input/Output Library
#include <string>
#include <iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions
class inventory{
private:
    int itemnum;
    int qty;
    float cst;
    float ttl;
public:
    inventory();
    inventory(int,int,float);
    void setNum(int item_Nm);
    void setQan(int qun);
    void setCst(int cst);
    void setTot();
    int getItemNum();
    int getQuant();
    float getCost();
    float getTotal();
};
//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int iNum,quant;     // Item Number, Quantity
    float cost,ttlcst;     // Cost, Total Cost
    //Initialize variables here
    
    //Map inputs to outputs here, i.e. the process
    cout << "Enter item number: ";
    cin  >> iNum;
    cout << "Enter item quantity: ";
    cin  >> quant;
    cout << "Enter item cost: ";
    cin >> fixed >> setprecision(2) >> cost;
    if(iNum < 0 || quant < 0 || cost < 0)
        cout<<"Invalid Entry";
    else{
        inventory inv(iNum,quant,cost);
        cout << "Item Number  : " << inv.getItemNum() << endl;
        cout << "Item Quantity: " << inv.getQuant() << endl;
        cout << fixed << setprecision(2);
        cout << "Item Cost    : " << inv.getCost() << endl;
        cout << "Total Cost   : " << inv.getTotal() << endl;
    }
    //Display the results

    return 0;
}
inventory::inventory(){
    itemnum = 0;
    qty = 0;
    cst = 0;
    ttl = 0;
}
inventory::inventory(int num,int qnt,float cst){
    setNum(num);
    setQan(qnt);
    setCst(cst);
    setTot();
}
void inventory::setNum(int itemN){
        itemnum=itemN;
    }
void inventory::setQan(int quan){
        qty=quan;
    }
void inventory::setCst(int cos){
        cst=cos;
    }
void inventory::setTot(){
        ttl=cst*qty;
    }
int inventory::getItemNum(){
        return itemnum;
    }
int inventory::getQuant(){
        return qty;
    }
float inventory::getCost(){
        return cst;
    }
float inventory::getTotal(){
        return ttl;
    }

