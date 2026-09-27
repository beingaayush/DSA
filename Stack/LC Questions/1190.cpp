// Problem Statement:
// You are given a string s that consists of lower case English letters and brackets.
// Reverse the strings in each pair of matching parentheses, starting from the innermost one.
// Your result should not contain any brackets.

// Example 1:
// Input: s = "(abcd)"
// Output: "dcba"

// Example 2:
// Input: s = "(u(love)i)"
// Output: "iloveu"

// Core Idea:
// Use a stack + current string.
// - curr → current substring we are building.
// - ( → save curr in stack and start a new substring.
// - ) → reverse curr, then attach it to the string saved in stack.
// - Normal character → add to curr.
// In one line:  
// Whenever ) comes, reverse the current bracket content and merge it back with the string before (.

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        string reverseParentheses(string s){
            stack<string> st;
            string curr = "";

            for(char c : s){
                if(c == '('){
                    st.push(curr);
                    curr = "";
                }
                else if(c == ')'){
                    reverse(curr.begin(), curr.end());
                    curr = st.top() + curr;
                    st.pop();
                }
                else curr += c;
            }
            return curr;
        }
};