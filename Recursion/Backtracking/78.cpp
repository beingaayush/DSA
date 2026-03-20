// Problem Statement:-
// Given an integer array nums of unique elements, return all possible subsets (the power set).
// The solution set must not contain duplicate subsets.
// You can return the subsets in any order.
// CORE IDEA and INTUITION :- 78.txt (file)

// 🔹 Example:-
// Input: nums = [1,2,3]
// Output:
// [
//  [],
//  [1],
//  [2],
//  [3],
//  [1,2],
//  [1,3],
//  [2,3],
//  [1,2,3]
// ]

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        void solve(int i, vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans){
            //base case
            if(i == nums.size()){
                ans.push_back(temp);
                return;
            }

            //take
            temp.push_back(nums[i]);
            solve(i+1, nums, temp, ans);

            //Backtrack
            temp.pop_back();

            //not take
            solve(i+1, nums, temp, ans);
        }
        vector<vector<int>> subsets(vector<int> &nums){
            vector<vector<int>> ans;
            vector<int> temp;
            solve(0, nums, temp, ans);
            return ans;
        }
};