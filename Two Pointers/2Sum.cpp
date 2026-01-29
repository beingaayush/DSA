// problem statement :-
// find 2 numbers from this sorted array whose sum == target
// arr = [2, 4, 5, 8, 11, 14]
// target = 13


#include <bits/stdc++.h>
using namespace std;

void twoSum(int arr[], int n, int target){
    int i = 0, j = n-1;
    while(i<j){
    int sum = arr[i] + arr[j];
        if(sum == target){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            return;
        }
        else if(sum < target){
            i++;
        }
        else if(sum > target){
            j--;
        }
    }
    cout<<"Null"<<endl;
}

int main(){
    int n = 6;
    int arr [n] = {2,4,5,8,11,14};
    int target = 13;
    twoSum(arr,n,target);
    return  0;
}

