// Problem Statement:
// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.

// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool fun(unordered_map<char, int> demand, unordered_map<char, int> avail){
            for(auto i:demand){
                char c = i.first;
                int freqDemand = i.second;
                int freqAvail = avail[c];
                if(freqAvail <freqDemand){
                    return false;
                }
            }
            return true;
        }
        bool canConstruct(string ransomNote, string magazine){
            unordered_map<char, int> demand;
            unordered_map<char, int> avail;

            for(int i=0; i<ransomNote.size(); i++){
                demand[ransomNote[i]]++;
            }
            for(int i=0; i<magazine.size(); i++){
                avail[magazine[i]]++;
            }
            return fun(demand, avail);
        }
};