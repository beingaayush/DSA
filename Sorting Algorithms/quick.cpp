//pick a pivot element & placed into its correct position
//pick rest elements & throw smaller on the left and larger on the right
//repeat 2nd step until whole array get sorted

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i < j){
        while(arr[i] <= pivot && i <= high - 1){
            i++;
        }
        while(arr[j] > pivot && j >= low){
            j--;
        }
        if(i<j) swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);     //left half
        quickSort(arr, pIndex + 1, high);   //right half
    }
}

int main(){
    int n;
    cout<<"enter array size = ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];

    quickSort(arr,0,n-1);

    for(auto x : arr) cout<<x<<" ";
    return  0;
}