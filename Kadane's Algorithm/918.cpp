// Problem Statement:-
// You’re given an integer array nums where the array is circular.
// This means the last element connects back to the first.
// Return the maximum possible sum of a non-empty subarray of nums.
// A subarray can either:
// lie normally inside the array
// or wrap around the end to the beginning (because it’s circular)
// CORE IDEA ----  we are calc totalsum or entire arr, maxsum of subarr, minssum of subarr | then totalsum - minsum | then return max one among totalsum and maxsum
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int circularSubarr(vector<int> &nums){
        int currMaxSum = nums[0];
        int currMinSum = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];
        int totalSum = nums[0];

        for(int i=1; i<nums.size(); i++){
            totalSum += nums[i];

            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            maxSum = max(maxSum, currMaxSum);

            currMinSum = min(currMinSum + nums[i], nums[i]);
            minSum = min(minSum, currMinSum);
        }
        if(maxSum < 0) return maxSum;
        return max(maxSum, totalSum - minSum);
    }
};

int main(){
    Solution Sol;
    vector<int> nums = {5, -3, 5};
    cout << Sol.circularSubarr(nums);
    return  0;
}