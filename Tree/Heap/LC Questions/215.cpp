// Problem Statement:
// Given an integer array nums and an integer k, return the kth largest element in the array.
// k is based on sorted order, not distinct elements.
// Example: nums = [3,2,1,5,6,4], k = 2
// Sorted descending: [6,5,4,3,2,1]
// Answer = 5

// Core Idea :
// Pattern: Heap / Priority Queue
// Use a Min Heap of size k:
// Traverse every element.
// Insert the element into the min heap.
// If heap size becomes greater than k, remove the smallest element.
// After processing everything, the heap contains the k largest elements.
// The smallest among those k elements is exactly the kth largest.

// nums:  [3, 2, 1, 5, 6, 4]
// k = 2
// Keep only 2 largest:
// [3] → [2,3] → [3,5] → [5,6] → [4,6]

//                      ↑
//                 kth largest

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int kthLargest(vector<int> &nums, int k){
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto num : nums){
            pq.push(num);
            
            if(pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};