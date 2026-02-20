#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int longestPalindrome(string s){
            int n = s.size();
            bool hasOdd = false;
            int res = 0;
            unordered_map<char,int> mpp;
            for(int i=0; i<n; i++){
                mpp[s[i]]++;
            }
            for(auto i:mpp){
                int val = i.second;
                if(val % 2 == 0){
                    res += val;
                }
                else{
                    res += val - 1;
                    hasOdd = true;
                }
            }
            if(hasOdd) return res + 1;
            return res;
        }
};