#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>

using namespace std;

int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory

int main() {
   //Declaring variables
int row,col;
int **nos;
  
   nos=getData(row,col);   
   printDat(nos,row,col);
      ++row;
   ++col;
   nos=augment(nos,row,col);
   printDat(nos,row,col);
   destroy(nos,row);
  
   return 0;
}
//Get the Matrix Data
int **getData(int &row,int &col)
{
   cin>>row>>col;
   // Creating 2-D array Dynamically
int** arr = new int*[row];
for (int i = 0; i < row; ++i)
arr[i] = new int[col];
  
for(int i=0;i<row;i++)
{
   for(int j=0;j<col;j++)
   {
       cin>>arr[i][j];
           }
       }
       return arr;

}

//Print the Matrix
void printDat(const int * const *nos,int row,int col){
   for(int i=0;i<row;i++){
       for(int j=0;j<col;j++){
        cout<<nos[i][j];
            if(j<col-1) cout << " ";
       }
       if(i<=row && i<=row-1) cout<<endl;
   }
}

//Augment the original array
int **augment(const int * const *nos,int row,int col) {
// Creating 2-D array Dynamically
int** arr = new int*[row];
for (int i = 0; i < row; ++i)
arr[i] = new int[col];
  
  
for(int i=0;i<row;i++) {
   for(int j=0;j<col;j++) {
    if(i==0) {
    arr[i][j]=0;
               }
    else if(j==0) {
   arr[i][j]=0;                  
              }
    else
        {
    arr[i][j]=nos[i-1][j-1];
               }
           }
       }
    return arr;
}

//Destroy the Matrix, i.e., reallocate memory
void destroy(int **nos,int size) {
   for (int i = 0; i < size; i++) {
    delete[] nos[i];
    }
}