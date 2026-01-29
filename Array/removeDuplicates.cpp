//reprint array, after removing duplicates (2 pointer approaced used here)
//array should be sorted
#include <bits/stdc++.h>
using namespace std;

int duplicates(int arr[], int n){
    int i = 0;
    for(int j=1;j<n;j++){
        if(arr[i] != arr[j]){
            arr[i+1] = arr[j];
            i++;            
        }
    }
    return i+1;
}

int main(){
    int n =5;
    int arr [n] = {1,2,2,3,3};
    int newarr = duplicates(arr,n);
    for(int i=0;i<newarr;i++) cout<<arr[i];
    return  0;
}