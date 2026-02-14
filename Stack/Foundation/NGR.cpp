// Next Greater Right (NGR)
// Statement: arr[i] ke right side me jo pehla greater element mile, wahi answer.

// Core Idea:-
// Traverse (Right→Left):
// Stack me right-side candidates rakho
// Jab tak st.top() <= arr[i], pop (kyuki ye kabhi greater nahi ban sakta)
// Top bacha to wahi answer, warna -1
// Then arr[i] push

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> nextGreaterRight(const vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(arr[i]); 
        }
        return ans;
    }
};