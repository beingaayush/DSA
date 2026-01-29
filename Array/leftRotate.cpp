//move 1st element to last and shift rest of the elements to left
#include <bits/stdc++.h>
using namespace std;
void leftRotate(int arr[], int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}

int main(){
    int n = 4;
    int arr [n] = {1,2,3,4};
    
    leftRotate(arr,n);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return  0;
}