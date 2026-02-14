// Next Smaller Right (NSR)
// Statement: arr[i] ke right side me jo pehla smaller element mile, wahi answer.

// core idea:
// Traverse (Right→Left):
// Jab tak st.top() >= arr[i], pop (kyuki smaller nahi ban sakta)
// Top bacha to answer, warna -1
// Push current

#include <bits/stdc++.h>
using namespace std;
class solution{
public:
    vector<int> nextSmallerRight(const vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                st.top();
            }
            st.push(arr[i]);
        }
        return ans;
    }
};