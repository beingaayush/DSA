//Statement:- Find the smallest index i such that arr[i] >= target.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int lowerBound(vector<int>& arr, int target) {
            int n = arr.size();
            int low = 0;
            int high = n - 1;
            int ans = n;   // default: not found case

            while (low <= high) {
                int mid = low + (high - low) / 2;

                if (arr[mid] >= target) {
                    ans = mid;        // potential answer
                    high = mid - 1;   // try to find smaller index on left
                } 
                else {
                    low = mid + 1;    // move right
                }
            }

            return ans;
        }
};