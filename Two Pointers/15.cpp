// problem statement 
// Given an array arr, find all unique triplets [i,j,k] such that i + j + k = 0.
// output - 1st unique triplet = -1 -1 2  | 2nd unique triplet = -1 0 1

#include <bits/stdc++.h>
using namespace std;
void threeSum(vector<int> &arr){
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(),arr.end());

    for(int i=0;i<n-2;i++){
        if(i>0 && arr[i] == arr[i-1]) continue;       // i!=0, i>0 warna sum 0 nhi ayega && remove duplicates
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            
            if(sum == 0){
                ans.push_back({arr[i],arr[j],arr[k]});
                j++;
                k--;

                while(j<k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
            else if(sum < 0) j++;
            else k--;
        }
    }
    for(auto &x: ans){
        for(int y:x) cout<<y<<" ";
    }
}
int main(){
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    threeSum(arr);
    
    return  0;
}