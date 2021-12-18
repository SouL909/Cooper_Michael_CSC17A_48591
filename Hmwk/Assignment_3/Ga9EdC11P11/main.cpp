/* 
 * File:   
 * Author: Michael Cooper
 * Created on 10/5/21
 * Purpose:  Prob 3
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
struct monthly { 
    float housing, util, housexp, transp, food, med, ins, ent, clothes, misc, budSum;
};

//Function Prototypes
void hbug ( monthly a, monthly b);
void ubug ( monthly a, monthly b);
void hebug ( monthly a, monthly b);
void tbug ( monthly a, monthly b);
void foodbug ( monthly a, monthly b);
void medbug ( monthly a, monthly b);
void insbug ( monthly a, monthly b);
void entbug ( monthly a, monthly b);
void clobug ( monthly a, monthly b);
void miscbug ( monthly a, monthly b);
void totbug ( monthly a, monthly b);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    
    //Initialize Variables
    monthly budget;
    budget.housing = 500;
    budget.util = 150;
    budget.housexp = 65;
    budget.transp = 50;
    budget.food = 250;
    budget.med = 30;
    budget.ins = 100;
    budget.ent = 150;
    budget.clothes = 75;
    budget.misc = 50;
    
    monthly spent;
    cout << "Enter housing cost for the month:$" << endl;
    cin  >> spent.housing;
    cout << "Enter utilities cost for the month:$" << endl;
    cin  >> spent.util;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin  >> spent.housexp;
    cout << "Enter transportation cost for the month:$" << endl;
    cin  >> spent.transp;
    cout << "Enter food cost for the month:$" << endl;
    cin  >> spent.food;
    cout << "Enter medical cost for the month:$" << endl;
    cin  >> spent.med;
    cout << "Enter insurance cost for the month:$" << endl;
    cin  >> spent.ins;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin  >> spent.ent;
    cout << "Enter clothing cost for the month:$" << endl;
    cin  >> spent.clothes;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin  >> spent.misc;
    
    //Process or map Inputs to Outputs
    
    //Display Outputs
     hbug ( budget, spent);
     ubug ( budget, spent);
     hebug ( budget, spent);
     tbug ( budget, spent);
     foodbug ( budget, spent);
     medbug ( budget, spent);
     insbug ( budget, spent);
     entbug ( budget, spent);
     clobug ( budget, spent);
     miscbug ( budget, spent);
     totbug ( budget, spent);
     
    //Exit stage right!
    return 0;
}

void hbug ( monthly a, monthly b) {
    cout << "Housing ";
    if ( a.housing < b.housing) {
        cout << "Over" << endl;
    }
    else if ( a.housing > b.housing) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    } 
}

void ubug ( monthly a, monthly b) {
    cout << "Utilities ";
    if ( a.util < b.util) {
        cout << "Over" << endl;
    }
    else if ( a.util > b.util) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    } 
}

void hebug ( monthly a, monthly b) {
    cout << "Household Expenses ";
    if ( a.housexp < b.housexp) {
        cout << "Over" << endl;
    }
    else if ( a.housexp > b.housexp) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    } 
}

void tbug ( monthly a, monthly b) {
    cout << "Transportation ";
    if ( a.transp < b.transp) {
        cout << "Over" << endl;
    }
    else if ( a.transp > b.transp) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    } 
}
void foodbug ( monthly a, monthly b) {
    cout << "Food ";
    if ( a.food < b.food) {
        cout << "Over" << endl;
    }
    else if ( a.food > b.food) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    } 
}

void medbug ( monthly a, monthly b) {
    cout << "Medical ";
    if ( a.med < b.med) {
        cout << "Over" << endl;
    }
    else if ( a.med > b.med) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    }     
}

void insbug ( monthly a, monthly b) {
    cout << "Insurance ";
    if ( a.ins < b.ins) {
        cout << "Over" << endl;
    }
    else if ( a.ins > b.ins) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    }     
}

void entbug ( monthly a, monthly b) {
    cout << "Entertainment ";
    if ( a.ent < b.ent) {
        cout << "Over" << endl;
    }
    else if ( a.ent > b.ent) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    }     
}

void clobug ( monthly a, monthly b) {
    cout << "Clothing ";
    if ( a.clothes < b.clothes) {
        cout << "Over" << endl;
    }
    else if ( a.clothes > b.clothes) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    } 
}

void miscbug ( monthly a, monthly b) {
    cout << "Miscellaneous ";
    if ( a.misc < b.misc) {
        cout << "Over" << endl;
    }
    else if ( a.misc > b.misc) {
        cout << "Under" << endl;
    }
    else {
        cout << "Even" << endl;
    } 
}

void totbug ( monthly a, monthly b) {
    float budSum = 0;
    a.budSum+=a.housing+a.util+a.housexp+a.transp+a.food+a.med+a.ins+a.ent+a.clothes+a.misc;
    b.budSum+=b.housing+b.util+b.housexp+b.transp+b.food+b.med+b.ins+b.ent+b.clothes+b.misc;
    if (a.budSum > b.budSum ) {
        cout << fixed << setprecision(2) << showpoint;
        cout << "You were $" << a.budSum-b.budSum << " under budget";
    }
    else if (a.budSum < b.budSum ) {
        cout << fixed << setprecision(2) << showpoint;
        cout << "You were $" << abs(a.budSum-b.budSum) << " over budget";
    }

}

