// Problem Statement:-
// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int firstUniqChar(string s){
            int n = s.size();
            unordered_map<char, int> mpp;  //key = string, val = freq/count

            for(int i=0; i<n; i++){
                mpp[s[i]]++;
            }
            for(int  i=0; i<n; i++){
                if(mpp[s[i]] == 1){
                    return i;
                }
            }
            return -1;
        }
};