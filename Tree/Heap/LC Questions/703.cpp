// Problem Statement:
// (Har baar ek naya number add hone par, current numbers mein se K-th largest number batao.
// Bas. Stream ka matlab sirf itna hai ki numbers one-by-one add ho rahe hain.)\

// You are given an integer k and an initial list of numbers.
// Numbers are added one at a time using add(val).
// After every addition, return the k-th largest element among all numbers seen so far.
// Example: k = 3 | nums = [4, 5, 8, 2]
// add(3) → 4
// add(5) → 5
// add(10) → 5

// Core Idea :
// Maintain a Min Heap of size k.
// Add every number to the heap.
// If size becomes > k, remove the smallest.
// The heap now contains the k largest elements.
// Therefore, pq.top() = k-th largest.
// Pattern: Kth Largest → Min Heap of size K.

#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums){
            pq.push(num);
            if(pq.size() > k) pq.pop();
        } 
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) pq.pop();
        return pq.top();
    }
};