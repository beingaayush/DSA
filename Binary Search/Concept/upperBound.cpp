// Statement:- Find the smallest index i such that arr[i] > target.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    int upperBound(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] > target)
                high = mid - 1;   // eliminate right
            else
                low = mid + 1;    // eliminate left
        }

        return low;   // first index where arr[i] > target
    }
};    