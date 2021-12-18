/* Michael Cooper
   Code-e Prob 6
   10/2/21 8PM
*/
#include <iostream>
using namespace std;

int *getData(int &n) {
int *arr = new int[n];
for (int i=0; i<n; i++) {
cin >> arr[i];
}
return arr;

}

int *augment(const int *arr, int n) {
int *res = new int[n + 1];
res[0] = 0;
for (int i = 0; i<n; i++){
res[i + 1] = arr[i];
}
return res;
}

void prntAry(const int *arr, int n) {

for (int i = 0; i<n; i++) {
    if (i==0){
    cout << arr[i];
        }
    else{
    cout<<" "<<arr[i];
        }
    }
}

int main() {
int n;
cin >> n;
int *arr = getData(n);
prntAry(arr, n);
cout<<endl;
arr = augment(arr, n);
prntAry(arr, n+1);
}