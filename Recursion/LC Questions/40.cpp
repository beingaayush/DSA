// Problem Statement:-
// You are given an array of integers candidates and an integer target.
// Return all unique combinations of candidates where the chosen numbers sum to target.
// ⚠️ Important Rules
// Each number can be used at most once
// → You cannot reuse the same index
// The array may contain duplicates
// The result must not contain duplicate combinations


#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        void solve(int idx, vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &temp)
        {
            //base case
            if(target == 0){
                ans.push_back(temp);
                return;
            }

            for(int i=idx; i<arr.size(); i++){
                // skip duplicates
                if(i > idx && arr[i] == arr[i-1]) continue;

                //pruning
                if(arr[i] > target) break;

                temp.push_back(arr[i]);
                solve(i+1, arr, target - arr[i], ans, temp);
                temp.pop_back();
            }
        }
        vector<vector<int>> combinationSum(vector<int> &candidates, int target){
            sort(candidates.begin(), candidates.end());
            vector<vector<int>> ans;
            vector<int> temp;
            solve(0, candidates, target, ans, temp);
            return ans;
        }
};