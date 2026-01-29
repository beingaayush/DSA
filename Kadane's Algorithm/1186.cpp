// Problem Statement:
// You are given an integer array arr.
// You may delete at most one element from the array. After the deletion (or without deleting anything),
// choose a non-empty contiguous subarray.
// Return the maximum possible subarray sum.

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int oneDeletion(vector<int> &arr){
        int n = arr.size();
        int noDelete = arr[0];
        int oneDelete = 0;
        int res = arr[0];

        for(int i=0; i<n; i++){
            //deletion not happening cases
            int v1 = arr[i];                    //subarr with the element itself
            int v2 = noDelete + arr[i];         //subarr of Previous elements + current
            //deletion happening cases
            int v3 = oneDelete + arr[i];        //previous subarr with one deleted element + current
            int v4 = noDelete;                  //current subarr deleted here | noDelete - last subarr

            noDelete = max(v1, v2);
            oneDelete = max(v3, v4);
            res = max(res, max(noDelete, oneDelete));
        }
        return res;
    }
};

int main(){
    Solution Sol;
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Sol.oneDeletion(arr);
    return  0;
}