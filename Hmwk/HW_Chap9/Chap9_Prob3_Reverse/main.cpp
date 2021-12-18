/* Michael Cooper
   Code-e Prob 3
   9/30/21 8PM
*/

//System Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <vector>
using namespace std;

//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes
int *getData(int &);
int *sort(const int *,int); 
int *reverse(const int *,int); 
void prntDat(const int *,int); 
//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    int* nos;
    int size;
    
    //Initialize variables
    nos=getData(size);
    nos=sort(nos,size);
    
    //Process, map inputs to outputs
    prntDat(nos,size);
    //Display your initial conditions as well as outputs.
    nos=reverse(nos,size);
    cout<<endl;
    prntDat(nos,size);

    //Exit stage right
   return 0;
}

int *getData(int &size){
   cin >> size;
   int* nos = new int[size];
  
for(int i = 0; i < size; i++) {
   cin >> nos[i];
   }
   return nos;
}

int *sort(const int *nos,int size){
    int* array = new int[size];
    for( int i = 0; i < size; i++ ) {
        array[i]=nos[i];
    }
    int temp;
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}

int *reverse(const int *nos,int size){
    int* array = new int[size];
    for(int i=0;i<size;i++){
    array[i]=nos[i];
    }
    int temp;
    for (int i = 0; i < size; i++){
        for (int j = i + 1; j < size; j++){
            if (array[i] < array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    return array;
}

void prntDat(const int *nos,int size){
   for(int i=0;i<size;i++){
    if (i==0){
        cout<<nos[i];
            }
        else{
            cout<<" "<<nos[i];
        }
    }
}