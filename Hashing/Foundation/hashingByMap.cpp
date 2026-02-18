// Use it if:
// Keys are numbers or characters but may be very large or unknown.
// You want keys in sorted order. *
// time complexity - O(logn) *

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // pre compute
    map<int, int> mpp;
    for(int i=0;i<n;i++){
        mpp[arr[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        //fetch
        cout << mpp[num] << endl;
    }
    return  0;
}