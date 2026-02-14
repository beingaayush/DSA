// Problem :
// You’re given two sorted arrays arr1 and arr2.
// Merge both arrays as one sorted array in-place.

#include <bits/stdc++.h>
using namespace std;
void mergeBoth(int arr1[], int n, int arr2[], int m, int res[]){
    int i = 0;
    int j = 0;
    int idx = 0;  // 0 index se element ko rkhnge res array mein

    while(i<n and j<m){
        if(arr1[i] <= arr2[j]){
            res[idx] = arr1[i];
            idx++;
            i++;
        }
        else{
            res[idx] = arr2[j];
            idx++;
            j++;
        }
    }
    while(i<n){
        res[idx] = arr1[i];
        idx++;
        i++;
    }
    while(j<m){
        res[idx] = arr2[j];
        idx;
        j++;
    }
}

int main(){
    //first array, with size n
    int n = 3;
    int arr1[n] = {4,8,9};
    //second array, with size m
    int m = 4;
    int arr2[m] = {2,3,5};
    
    int res[n + m];

    mergeBoth(arr1,n,arr2,m,res);
    for(int i=0;i<n+m;i++) cout << res[i]<<" ";

    return  0;
}