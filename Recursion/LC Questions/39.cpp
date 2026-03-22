// Problem statement:
// Given an array of distinct integers candidates and a target integer target,
// return all unique combinations of candidates where the chosen numbers sum to target.
// You may use the same number unlimited times.
// Two combinations are different if their frequency of at least one chosen number is different.


#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        void solve(int idx, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> temp){
            //base case
            if(idx == arr.size() || target < 0){
                if(target == 0){
                    ans.push_back(temp);
                }
                return;
            }

            //pick
            temp.push_back(arr[idx]);
            solve(idx, arr, target - arr[idx], ans, temp);

            //backtrack
            temp.pop_back();

            //not pick
            solve(idx + 1, arr, target, ans, temp);
        }
        vector<vector<int>> combinationSum(vector<int> &candidates, int target){
            vector<vector<int>> ans;
            vector<int> temp;
            solve(0, candidates, target, ans, temp);
            return ans;
        }
};