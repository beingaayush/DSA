#include <bits/stdc++.h>
using namespace std;

// tabulation
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n);

        // First 2 stairs
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Minimum cost to reach each stair
        for(int i = 2; i < n; i++) {
            // Come from previous 1 or 2 stairs
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // Top can be reached from last or second-last stair
        return min(dp[n - 1], dp[n - 2]);
    }
};




// memoization
class Solution {
public:
    int solve(int i, vector<int>& cost, vector<int>& dp) {
        // First 2 stairs
        if(i == 0) return cost[0];
        if(i == 1) return cost[1];

        // Already calculated
        if(dp[i] != -1) return dp[i];

        // Come from previous 1 or 2 stairs
        dp[i] = cost[i] + min(
            solve(i - 1, cost, dp),
            solve(i - 2, cost, dp)
        );

        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n, -1);

        // Top can be reached from last or second-last stair
        return min(
            solve(n - 1, cost, dp),
            solve(n - 2, cost, dp)
        );
    }
};