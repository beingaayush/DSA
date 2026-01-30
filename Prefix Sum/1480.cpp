// Problem Statement:-
// Given an integer array nums, return an array runningSum where:
// runningSum[i] = sum of nums[0] + nums[1] + ... + nums[i]

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> runningSum(vector<int> & nums){
        vector<int> runningsum(nums.size());    //for storing each sum till idx i
        int sum = 0;

        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            runningsum[i] = sum;
        }
        return runningsum;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4};
    sol.runningSum(nums);
    return  0;
}