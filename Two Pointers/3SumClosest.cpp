//problem statement:- 
//Given an integer array and a target,
//find 3 numbers such that their sum is closest to target.
//3 sum concept use hoga, bas duplicates remove ki need nhi h bcoz doesn't ask !

#include <bits/stdc++.h>
using namespace std;

int closestSum(vector<int> &arr, int target){
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int closestsum = arr[0]+arr[1]+arr[2];

    for(int i=0;i<n-2;i++){
        int j =i+1;
        int k = n-1;

        while(j<k){
            int sum = arr[i]+arr[j]+arr[k];
            if(abs(sum-target) < abs(closestsum-target)){
                closestsum = sum;
            }
            if(sum < target) j++;
            else if(sum > target) k--;
            else return sum; //(sum == target)
        }
    }
    return closestsum;
}
int main(){
    vector<int> arr = {-1, 2, 1, -4};
    int target = 1;

    cout << closestSum(arr,target);
    return  0;
}