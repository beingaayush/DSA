//find second Largest element from the array
#include <bits/stdc++.h>
using namespace std;

int secondLargest(int arr[], int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=1;i<n;i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}

int main(){
    int n = 5;
    int arr [n];
    for(int i=0;i<n;i++) cin>>arr[i];

    secondLargest(arr,n);
    return  0;
}