// Problem Statement:-
// You are given a string s consisting of lowercase English letters.
// You must repeatedly remove pairs of adjacent identical characters from the string.
// Whenever two same characters are next to each other, remove both.
// After removing a pair, the remaining characters may form new adjacent duplicates, which must also be removed.
// Continue this process until no adjacent duplicate characters remain.
// Return the final string after all possible removals.
// Rules:-
// Removal is always done in pairs.
// Removal is repeated, not just once.
// The final string may be empty.
// Order of remaining characters must be preserved.

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    string removeDuplic(string s){
        stack<char> st;
        string res;
        for(int i=0; i<s.size(); i++){
            if(st.empty() || st.top() != s[i]){
                st.push(s[i]);
            }
            else{
                st.pop();
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
int main(){
    Solution sol;
    string s = "abbaca";
    sol.removeDuplic(s);
    return  0;
}