// Problem Statement
// You are given an integer array nums and an integer k.
// Return the number of subarrays whose sum is divisible by k.

// Core Idea :- (what we're doing)
// Walk through the array - calculate prefix sum at index i
// At each step compute: 
// rem = prefixSum % k
// (if negative → fix it by adding k)
// Count how many times this remainder has appeared before
// Add that count to the answer
// Store/update remainder frequency


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int divsbleByK(vector<int> & nums, int k){
        unordered_map<int,int> freq;
        freq[0] = 1;
        int prefix = 0;
        int count = 0;

        for(int i=0; i<nums.size(); i++){
            prefix += nums[i];
            int rem = prefix % k;
            if(rem < 0) rem += k;  //to handle -ve remainder
            count += freq[rem];
            freq[rem]++;
        }
        return count;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {4,5,0,-2,-3,1};
    int k = 5;
    cout << sol.divsbleByK(nums, k);
    return  0;
}