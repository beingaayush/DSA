//check weather the array is sorted or not
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;
    int arr [n] = {1,2,3,4};
    for(int i=0;i<n;i++){
        if(arr[i] >= arr[i-1]){

        }
        else{
            return false;
        }
    }
    return  true;
}