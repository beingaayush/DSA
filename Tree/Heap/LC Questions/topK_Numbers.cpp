// Problem Statement:
// Given an unsorted array of numbers and an integer K, find the K largest numbers in the array.
// Example:
// Input: [3, 1, 5, 12, 2, 11], K = 3
// Output: [5, 12, 11]

// Core Idea :
// Hume K largest elements chahiye, aur array ke saare elements sort karna unnecessary hai.

// Use a Min Heap of size K:
// > Pehle K elements heap me daalo.
// > Heap ka top hamesha current K elements me smallest hoga.
// > Remaining har element ke liye:
// > Agar num > heap.top(), then:
// > smallest element ko remove karo
// > current num insert karo
// > End me heap me exactly K largest elements honge.

// Time: O(N log K)
// Space: O(K)

#include <bits/stdc++.h>
using namespace std;

vector<int> findKLargestNumbers(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : nums) {
        minHeap.push(num);

        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    vector<int> result;

    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

    return result;
}