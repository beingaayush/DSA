#include <bits/stdc++.h>
using namespace std;

// memoization

class Solution {
public:
    int f(int n, vector<int> &dp){
        // base case
        if(n <= 2) return n;

        // if dp already calculated
        if(dp[n] != -1) return dp[n];

        // store + recurrence call
        return dp[n] = f(n-1, dp) + f(n-2, dp); 
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp);
    }
};

// tabulation

class Solution{
    public:
        int climbstairs(int n){
            if(n <= 2) return;

            vector<int> dp(n+1, -1);

            dp[1] = 1;
            dp[2] = 2;

            for(int i=3; i<=n; i++){
                dp[i] = dp[i-1] + dp[i-2];
            }
            return dp[n];
        }
};