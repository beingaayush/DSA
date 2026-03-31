//find second smallest element from the array
#include <bits/stdc++.h>
using namespace std;

int secondSmallest(int arr[], int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i] > smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < ssmallest){
            ssmallest = arr[i];
        }
    }
    return ssmallest;
}

int main(){
    int n = 5;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    secondSmallest(arr,n);
    return  0;
}