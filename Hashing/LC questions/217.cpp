// Problem Statement: 
// Given an integer array nums, return true if any value appears at least twice in the array,
// and return false if every element is distinct.

// Example 1: 
// Input: nums = [1,2,3,1] 
// Output: true 
// Explanation: The element 1 occurs at the indices 0 and 3.

// Example 2: 
// Input: nums = [1,2,3,4] 
// Output: false 
// Explanation: All elements are distinct.

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool containDuplicate(vector<int> &nums){
        unordered_set<int> st;
        for(int x : nums){
            if(st.count(x)) return true;
            else st.insert(x);
        }
        return false;
    }
};