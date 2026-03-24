// Problem Statement:
// Given an array nums of distinct integers, return all possible permutations.
// You can return the answer in any order.
// Example 1:- Input: nums = [1,2,3] | Output:
// [
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
// ]
// Example 2:- Input: nums = [0,1] Output: [[0,1],[1,0]]

// Core Idea:
// Use backtracking
// Maintain:- temp → current permutation | used[] → track which elements are already picked
// Flow:- Loop through all elements
// If element is not used:- pick it → add to temp | mark as used | recurse
// backtrack → remove + unmark
// Base case:- if temp.size() == n → push into answer

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        void solve(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, vector<bool> &used){
            //base case
            if(temp.size() == nums.size()){
                ans.push_back(temp);
                return;
            }
            for(int i=0; i<nums.size(); i++){
                if(used[i] == true) continue;

                //pick
                temp.push_back(nums[i]);
                used[i] = true;
                solve(nums, ans, temp, used);   //recurse

                //backtrack
                temp.pop_back();
                used[i] = false;   //unmark

            }
        }
        vector<vector<int>> perumte(vector<int> &nums){
            vector<vector<int>> ans;
            vector<int> temp;
            vector<bool> used(nums.size(), false);

            solve(nums, ans, temp, used);
            return ans;
        }      
};