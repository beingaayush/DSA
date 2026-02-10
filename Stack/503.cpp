// Problem Statement:-
// Circular array given. For each element, find the next greater element while moving right (wrap allowed). If none, return -1.

// Core idea (no fluff):
// Monotonic decreasing stack + simulate circular array by iterating 2n times.
// Push indices only in the first pass. Resolve answers when a greater element appears.
// ( imagine the array 2 times :) ) -> arr = [1,2,1] then --> [1,2,1][1,2,1]


#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        int n = nums.size();              
        vector<int> res(n, -1);           // answer array, default -1

        stack<int> st;                    // stack me direct VALUES rahengi

        // 2*n loop = circular array ko handle karne ke liye
        for (int i = 2*n - 1; i >= 0; i--) {

            int idx = i % n;              // circular index (wrap around)

            // jab tak stack ka top current value se chhota ya barabar hai
            // unko hata do (kaam ka nahi)
            while (!st.empty() && st.top() <= nums[idx]) {
                st.pop();
            }

            // agar stack empty nahi hai
            // top wali value hi next greater element hai
            if (!st.empty()) {
                res[idx] = st.top();
            }

            // current value stack me daal do
            st.push(nums[idx]);
        }

        return res;                       
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,1};
    sol.nextGreaterElements(nums);
}