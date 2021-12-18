/* Michael Cooper
   Code-e Prob 5
   10/1/21 8PM
*/
#include <iostream>
#include <random>
using namespace std;
//User Libraries

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int **getData(int &n, int &m){
//Set the Random number seed
    
    //Declare variables
    
    //Initialize variables
    
    //Process, map inputs to outputs
    cin >> n >> m;
    int **array = new int *[n];
    for (int i = 0; i < n; i++){
        array[i] = new int[m];
        for (int j = 0; j < m; j++)
            cin >> array[i][j];
    }
    //Display your initial conditions as well as outputs.
    
    //Exit stage right
    return array;
}

void prntDat(const int *const *array, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        if (j==0){
        cout<<array[i][j];
        }
        else {
            cout<<" "<<array[i][j];
        }
        cout << endl;
    }
}

//Deallocate memory
void destroy(int **array, int n, int m) {
    // delete each row
    for (int i = 0; i < n; i++)
        delete[] array[i];
    delete array;
}

//Return the Sum
int sum(const int *const *array, int n, int m) {
    int Sum = 0;
    // for each row
    for (int i = 0; i < n; i++)
    // for each columm
    for (int j = 0; j < m; j++)
      Sum += array[i][j];
    return Sum;
}

int main(int argc, char const *argv[]) {
    int **array, n, m;
    array = getData(n, m);
    prntDat(array, n, m);
    cout << sum(array, n, m);
    destroy(array, n, m);
    return 0;
}