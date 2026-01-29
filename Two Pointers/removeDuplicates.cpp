// NOTE:- array sort h to ok, otherwise sort it first !
// QN.1 -  Return the no. of unique elements after removing duplicates

#include <bits/stdc++.h>
using namespace std;
int duplicates(int arr[], int n){
    int i = 0;
    int j = 1;
    while(j<n){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
        j++;
    }
    return i+1;
}
int main(){
    int n = 5;
    int arr [n] = {1,1,2,2,3};
    cout << duplicates(arr,n);
    return  0;
}

//QN.2 - reprint the array, after removing duplicates
#include <bits/stdc++.h>
using namespace std;
int duplicates(int arr[], int n){
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j] != arr[i]){
            i++;
            arr[i] = arr[j];
        }
    }
    return i+1;
}
int main(){
    int n = 6;
    int arr[n] = {1,1,1,2,2,3};
    int newArr = duplicates(arr,n);
    for(int i=0;i<newArr;i++) cout<<arr[i]<<" ";
    return  0;
}



//NOTE :- both qns. can be done using FOR loops.