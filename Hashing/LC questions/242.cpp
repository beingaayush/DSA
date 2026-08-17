// Problem Statement:
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> mpp;
        for(int i=0;i<s.size(); i++) mpp[s[i]]++;
        for(int i=0; i<t.size(); i++) mpp[t[i]]--;

        for(auto x : mpp){
            if(x.second != 0) return false;
        }
        return true;
    }
};