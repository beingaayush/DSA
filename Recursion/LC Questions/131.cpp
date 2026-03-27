// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s. 
// Example :
// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]

// Core idea:
// Har index se saare possible cuts try karo
// Agar idx → i substring palindrome hai:- usse include karo | baaki string pe recurse (i + 1)
// End tak pahunch gaye → valid partition mil gaya
// Har step pe backtrack (remove last added)
// Palindrome mile toh cut karo, warna skip karo — aur sab possibilities explore karo.

#include<bits/stdc++.h>
using namespace std;
class solution{
    public:
        // check if substring s[start...end] is palindrome
        bool isPalindrome(string &s, int start, int end){
            while(start <= end){
                if(s[start++] != s[end--]){
                    return false;
                }
            }
            return true;
        }

        void solve(int idx, string &s, vector<vector<string>> &ans, vector<string> &temp){
            //base case
            if(idx == s.size()){
                ans.push_back(temp);
                return;
            }
            
            // try all possible cuts starting from idx
            for(int i=idx; i<s.size(); i++){
                // if current substring is palindrome
                if(isPalindrome(s, idx, i)){
                    temp.push_back(s.substr(idx, i - idx + 1));          // pick substring
                    solve(i + 1, s, ans, temp);                         // move to next part (i + 1) not idx + 1, coz already explored idx...i
                    temp.pop_back();                                   // Backtrack
                }
            }
        }

        vector<vector<string>> partition(string &s){
            vector<vector<string>> ans;
            vector<string> temp;
            solve(0, s, ans, temp);
            return ans;
        }
};