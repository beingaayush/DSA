// Problem Statement:
// Given a string s, sort its characters in decreasing order based on their frequency.
// Characters with higher frequency should appear first.
// Example: Input:  s = "tree" | Output: "eert"
// Because:
// e → 2 times
// t → 1 time
// r → 1 time
// So e comes first.

// Core Idea :
// Use a HashMap to count the frequency of every character.
// Use a Max Heap to store:
// {frequency, character}
// Pop characters from the heap and add each character frequency times to the answer.

// Time: O(N log K)
// Space: O(N)

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for(char ch : s) mpp[ch]++;

        priority_queue<pair<int, char>> pq;
        for(auto x : mpp){
            int freq = x.second;
            char ch = x.first;

            pq.push({freq, ch});
        }

        string result;
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;

            pq.pop();

            while(freq--){
                result += ch;
            }
        }
        return result;
    }
};