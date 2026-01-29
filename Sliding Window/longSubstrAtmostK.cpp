// problem statement:- 
// Given a string s and an integer k, 
// return the length of the longest substring of s that contains at most k distinct/Unique characters.
// NOTE:- Distinct - Unique | if k=2 then hasmap should have 2 Unique chars | if exceeding then apply accordingly condition
// NOTE:- So when we say “at most k distinct characters”, it means:
// NOTE:- The substring can contain no more than k different (unique) characters, repetitions allowed.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestsubstrAtmostK(string s, int k){
        int n = s.size();
        unordered_map<char, int> mpp;
        int maxLen = 0;
        int left = 0;

        for(int right = 0; right<n; right++){
            mpp[s[right]]++;

            if(mpp.size() > k){
                mpp[s[left]]--;
                if(mpp[s[left]] == 0) mpp.erase(s[left]);
                left++;
            }
            if(mpp.size() <= k){
                maxLen = max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
};

 int main(){
    Solution sol;
    string s = "eceba";
    int k = 2;
    cout << sol.longestsubstrAtmostK(s,k);
 }