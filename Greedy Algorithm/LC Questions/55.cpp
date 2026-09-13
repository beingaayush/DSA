// Problem Statement:
// You are given an array nums.
// nums[i] tells you the maximum number of steps you can jump forward from index i.
// Start from index 0. Return true if you can reach the last index, otherwise return false.

// Example:
// nums = [2,3,1,1,4]
// Output: true

// Core Idea:
// Keep track of the farthest index reachable so far.
// maxIdx = max(maxIdx, i + nums[i]);
// For every index:
// If i > maxIdx → this index is unreachable → false
// Otherwise, update maxIdx
// If maxIdx >= last index → true
// In one line:
// Har index par check karo ki wahan tak pahunch sakte hain ya nahi,
// aur reachable range ko maximum possible index tak extend karte jao.

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool canjump(vector<int> &nums){
        int n = nums.size() - 1;
        int maxIdx = 0;
        
        for(int i=0; i<n; i++){
            if(i > maxIdx) return false;
            maxIdx = max(maxIdx, i + nums[i]);
        }
        return maxIdx >= n;
    }
};