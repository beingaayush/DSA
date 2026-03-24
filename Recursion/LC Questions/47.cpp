// Problem Statement:-
// Given a collection of numbers nums, which may contain duplicates, return all unique permutations.
// You can return the answer in any order.
// Example 1:- Input: nums = [1,1,2] | Output:
// [
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
// ]

// Core idea:
// Same as LC 46 + one critical rule to avoid duplicates
// Step 1: Sort the array
// 👉 So duplicates come together | [1,1,2]
// Step 2: Backtracking with used[]
// At each index i, before picking:
// 🔴 Skip condition (THIS is the whole question)
// if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;

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
                //if current is already used, leave it & move ahead
                if(used[i] == true) continue;

                //check for duplicates
                if(i> 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;

                //pick
                temp.push_back(nums[i]);
                used[i] = true;
                solve(nums, ans, temp, used);   //recurse

                //backtrack
                temp.pop_back();
                used[i] = false;
            }
        }
        vector<vector<int>> permute(vector<int> &nums){
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            vector<int> temp;
            vector<bool> used(nums.size(), false);

            solve(nums, ans, temp, used);
            return ans;
        }
};