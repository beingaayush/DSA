#include <bits/stdc++.h>
using namespace std;

//  tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        // No houses
        if(n == 0) return 0;

        // Only one house
        if(n == 1) return nums[0];

        vector<int> dp(n);

        // Only first house
        dp[0] = nums[0];

        // For first two houses, choose the one with more money
        dp[1] = max(nums[0], nums[1]);

        // Start from the third house
        for(int i = 2; i < n; i++) {

            // Option 1: Skip current house → dp[i-1]
            // Option 2: Rob current house → nums[i] + dp[i-2]
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        // Maximum money from all houses
        return dp[n - 1];
    }
};

// memoization
class Solution {
public:
    int solve(int i, vector<int>& nums, vector<int>& dp) {
        
        // No house left
        if(i < 0) return 0;

        // Already calculated
        if(dp[i] != -1) return dp[i];

        // Skip current house
        int skip = solve(i - 1, nums, dp);

        // Rob current house
        int rob = nums[i] + solve(i - 2, nums, dp);

        // Store and return maximum
        return dp[i] = max(skip, rob);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(n - 1, nums, dp);
    }
};