//Statement:- Find the smallest index i such that arr[i] >= target.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int lowerBound(vector<int>& arr, int target) {
            int low = 0, high = arr.size() - 1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

            if (arr[mid] >= target)
                high = mid - 1;
            else
                low = mid + 1;
            }   
            return low;   
        }
};