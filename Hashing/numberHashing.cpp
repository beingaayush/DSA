// This program counts how many times each number appears in an array and then answers queries asking:
// This is a basic hashing / frequency counting program.

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    //pre compute
    int hash[13] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]] += 1;
    }

    int q;                             //no. of queries you are going to ask/give
    cin>>q;
    while(q--){                       //eg- q = 5, go upto 5 & and input 5 numbers u want to search
        int number;
        cin>>number;
        //fetch
        cout << hash[number] << endl;
    }
    
    return  0;
}