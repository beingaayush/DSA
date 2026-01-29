// Problem statement:
// Given an integer array nums, find the contiguous subarray (containing at least one number) 
// which has the largest sum, and return that sum.

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxSubarray(vector<int> & nums){
        int bestSum = nums[0]; 
        int maxSum  = nums[0]; 

        for(int i=1; i<nums.size(); i++){
            int v1 = bestSum + nums[i]; // extend previous subarray
            int v2 = nums[i];           // start new subarray here
            
            bestSum = max(v1,v2);            // best subarray ending at i
            maxSum = max(maxSum, bestSum);   // best seen overall
        }
        return maxSum;
    }
};

int main(){
    Solution Sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Sol.maxSubarray(nums);
    return  0;
}