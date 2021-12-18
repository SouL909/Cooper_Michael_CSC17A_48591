/* Michael Cooper
   Code-e Prob 4
   10/1/21 8PM
*/

//System Libraries
#include <iostream>
using namespace std;
//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int *getData(int &n){
    //Set the Random number seed
    
    //Declare variables
    
    //Initialize variables
    
    //Process, map inputs to outputs
    cin >> n;
    int *array = new int[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return array;
}
int *sumAry(const int *array, int n){
    int *sum = new int[n];
    sum[0] = array[0];
    for (int i = 1; i < n; i++)
    sum[i] = sum[i - 1] + array[i];

    return sum;
}

void prntAry(const int *array, int n){
    for (int i = 0; i < n; i++)
    if (i==0){
        cout<<array[i];
        }
        else{
            cout<<" "<<array[i];
        }
}

int main(int argc, char const *argv[]){
    int n;
    int *array = getData(n);
    int *sum = sumAry(array, n);
    prntAry(array, n);cout<<endl;
    prntAry(sum, n);
    return 0;
}
