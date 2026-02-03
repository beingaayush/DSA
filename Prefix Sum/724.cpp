// Problem Statement:-
// find the pivot index of an array of integers. 
// The pivot index is defined as the index where the sum of all numbers strictly to the left 
// is equal to the sum of all numbers strictly to the right. 
// If no such index exists, return -1. 

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int pivotIndex(vector<int> & nums){
        int leftSum = 0;
        int rightSum = 0;
        int totalSum = 0;
        for(int i=0; i<nums.size(); i++) totalSum += nums[i];
        for(int i=0; i<nums.size(); i++){
            rightSum = totalSum - leftSum - nums[i];
            
            if(leftSum == rightSum) return i;
            leftSum += nums[i];
        }
        return -1;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,7,3,6,5,6};
    cout << sol.pivotIndex(nums);
    return  0;
}