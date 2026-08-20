// Problem Statement:
// Given an array nums and an integer k, return the k elements that appear most frequently.
// Example:  nums = [1,1,1,2,2,3], k = 2
// Answer = [1,2]
// Because:
// 1 → 3 times
// 2 → 2 times
// 3 → 1 time

// Core Idea :
// HashMap → count frequency of every number.
// Min Heap of size k → store {frequency, number}.
// If heap size > k, remove the smallest frequency.
// Remaining k elements are the answer.
// Pattern: Top K → Min Heap of size K

// Important things we got right : 
// mpp[num]++ → frequency counting ✅
// pair<int,int> = {frequency, number} ✅
// greater<pair<int,int>> → min heap ✅
// pq.size() > k → remove least frequent ✅
// .second → actual number, not frequency ✅
// Return vector<int> ✅

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k){
            // count frequency
            unordered_map<int, int> mpp;
            for(auto num : nums) mpp[num]++;
            
            // Min heap: {frequency, number}
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair< int, int>>> pq;
            
            // Keep only top k frequent elements
            for(auto x : mpp){
                pq.push({x.second, x.first});

                if(pq.size() > k) pq.pop();
            }

            // extract answer
            vector<int> ans;
            while(!pq.empty()){
                ans.push_back(pq.top().second);
                pq.pop();
            }
            return ans;
        }
};