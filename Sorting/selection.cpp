// Selection sort is a simple comparison-based sorting algorithm.
// Find the minimum element from the unsorted part.
// Swap it with the first element of the unsorted part.
// Continue until the whole array is sorted.

#include <bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int n){
    for(int i=0; i < n-1; i++){
        int minim = i;
        for(int j=i; j < n; j++){
            if(arr[j] < arr[minim]) minim = j;
        }
        //swap
        int temp = arr[minim];
        arr[minim] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selection_sort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return  0;
}