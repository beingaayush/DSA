// Problem Statement:
// Given an unsorted array of integers and an integer K, find the Kth smallest number in the array.
// Example:
// Input: nums = [1, 5, 12, 2, 11, 5], K = 3
// Output: 5
// Sorted array would be: [1, 2, 5, 5, 11, 12]
//                               ↑
//                         3rd smallest


// Core Idea:
// Max Heap of size K maintain karo.
// Heap mein current K smallest elements rakho.
// pq.top() = in K elements ka largest element.
// Agar koi new number pq.top() se chhota hai, toh top ko remove karke new number insert karo.
// End mein pq.top() hi Kth smallest number hoga.

// Time: O(N log K)
// Space: O(K)

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int findKthSmallestNumber(vector<int>& nums, int k){
            priority_queue<int> pq;
            for(auto num : nums){
                pq.push(num);

                if(pq.size() > k) pq.pop();
            }
            return  pq.top();
        }
};