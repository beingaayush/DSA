// Problem Statement
// Given a string s, find the length of the longest substring without repeating characters.
// Return an integer representing the length of the longest substring of s 
// that contains all unique characters.
// (expanding the window, basis of either the hashing still consists this element or not)
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestsubstrlen(string s){
        int n = s.size();
        int low = 0;
        int maxLen = 0;
        
        int hash[256];   //total special characters = 256.
        for(int i=0;i<256;i++) hash[i] = -1;

        for(int high=0;high<n;high++){
            //for skipping duplicates
            if(hash[s[high]] >= low){
                low = hash[s[high]] + 1;
            }
            hash[s[high]] = high; 
            maxLen = max(maxLen, high-low+1); // current length = (end - start + 1)
        }
        return maxLen;
    }
};

 int main(){
    Solution sol;
    string s = "cabcdebga";
    cout << sol.longestsubstrlen(s);
 }