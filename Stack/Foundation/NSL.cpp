// Next Smaller Left (NSL)
// Statement: arr[i] ke left side me jo pehla smaller element mile, wahi answer.

// core idea:
// Traverse (Left→Right):
// Jab tak st.top() >= arr[i], pop
// Top bacha to answer, warna -1
// Push current


#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int> nextSmallerLeft(const vector<int> &arr){
            int n = arr.size();
            vector<int> ans(n, -1);
            stack<int> st;

            for(int i = 0; i<n; i++){
                while(!st.empty() && st.top() >= arr[i]){
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