// Problem Statement:
// Determine whether the array was originally sorted in non-decreasing order and then rotated some number of times.
// Examples:
// [3,4,5,1,2] → ✅ True (sorted then rotated)
// [1,2,3,4,5] → ✅ True (rotated 0 times)
// [2,1,3,4] → ❌ False


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int breaks = 0;
        for(int i=0; i<n; i++){
            if(nums[i] > nums[(i+1)%n]) breaks++;
            if(breaks > 1) return false;
        }
        return true;
    }
};