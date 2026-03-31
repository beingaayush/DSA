//searching method
//use to search the element from an entire array

#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {6,7,8,4,1};
    int n = sizeof(arr);
    int num = 4;               //we've to search - in which idx 4 exists

    for(int i=0;i<n;i++){
        if(arr[i] == num){
            return i;
        }
    }
    return  -1;
}
