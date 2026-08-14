// Problem Statement: Given a string s, return the maximum length of a substring such that
// it contains at most two occurrences of each character.
// example: Input:  s = "bcbbbc" | Output: 4
// Core idea: - Sliding Window + Frequency Map


#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int maximumLengthSubstring(string s){
            int left = 0;
            int ans = 0;
            unordered_map<char, int> freq;

            for(int right=0; right<s.size(); right++){
                freq[s[right]]++;

                while(freq[s[right]] > 2){
                    freq[s[left]]--;
                    left++;
                }
                ans = max(ans, right-left+1);
            }
            return ans;
        }
};