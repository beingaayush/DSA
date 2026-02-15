// Problem Statement:
// You are given: - String (S) & integer (k)

// Task-
// Whenever k continue characters appear in the string, remove them.
// Keep doing this repeatedly until no more such groups exist.
// Return the final string after all possible removals.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        stack<pair<char,int>> st;

        for(int i = 0; i < n; i++) {

            char c = s[i];

            // Case 1: stack empty
            if(st.empty()) {
                st.push({c, 1});
            }
            else {

                // Case 2: same character as top
                if(st.top().first == c) {

                    pair<char,int> temp = st.top();
                    st.pop();

                    temp.second++;   // increase count

                    if(temp.second != k) {
                        st.push(temp);   // push only if count < k
                    }
                    // if count == k → do nothing (remove)
                }

                // Case 3: different character
                else {
                    st.push({c, 1});
                }
            }
        }

        // Build answer
        string ans = "";
        while(!st.empty()) {
            ans = string(st.top().second, st.top().first) + ans;
            st.pop();
        }

        return ans;
    }
};
