// Problem Statement:- 
// Given an array temperatures[], for each day tell how many days you must wait to get a warmer temperature.
// If no warmer day exists, answer 0 for that day.
// Core idea - next greater element starategy will be used

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> dailyTemp(vector<int> &temperature){
        int n = temperature.size();        
        vector<int> ans(n, 0); //answer array, initially initialized with 0
        stack<int> st;   //stack will store indices & track future warmer days

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && temperature[st.top()] <= temperature[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = 0;
            }
            else{ // stack ka top hi next warmer day hai
                ans[i] = st.top() - i;   //days gap - kitne din baad mila h next warmer temp /  gap = future index - current index
            }
            st.push(i);
        }
        return ans;
    }
};