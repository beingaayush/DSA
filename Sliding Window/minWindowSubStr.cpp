// Problem Statement:-
// Given two strings s and t, return the minimum window substring of s such that every character in t (including duplicates) is included in the window.
// If there is no such substring, return an empty string "".
// If there are multiple valid minimum windows, return any one of them.

#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    string minWindow(string s, string t){
        if(s.empty() || t.empty()) return " ";
        int l = 0;
        int r = 0;
        int n = s.size();
        int m = t.size();
        int sidx = -1;
        int count = 0;
        int minLen = INT_MAX;
        vector<int> hash(256,0);
        
        for(int i=0; i<m; i++) hash[t[i]]++;
        for(int i=r; r<n;r++){
            if(hash[s[r]] > 0){
                count++;
            }
            hash[s[r]]--;
            while(count == m){
                if(r-l+1 < minLen){
                    minLen = r-l+1;
                    sidx = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0){
                    count--;
                }
                l++;
            }
        }
        return sidx == -1 ? "":s.substr(sidx,minLen);
    }
};

int main(){
    Solution sol;
    string s = "ddaaabbac";
    string t = "abc";
    cout << sol.minWindow(s,t);
}