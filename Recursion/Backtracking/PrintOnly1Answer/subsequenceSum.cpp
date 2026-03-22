// Given:
// An array of integers arr of size n
// An integer k
// Task:- Find a subsequence of the array such that the sum of its elements = k

#include <bits/stdc++.h>
using namespace std;
bool solve(int i, int sum, vector<int>& arr, vector<int>& ds, int k){
    if(i == arr.size()){
        if(sum == k){
            for(int x : ds) cout << x << " ";
            cout << endl;
            return true;
        }
        return false;
    }

    // take
    ds.push_back(arr[i]);
    if(solve(i+1, sum + arr[i], arr, ds, k)) return true;
    ds.pop_back();

    // not take
    if(solve(i+1, sum, arr, ds, k)) return true;

    return false;
}