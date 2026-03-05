// Problem Statement:-
// You are given a sorted array that has been rotated at some unknown pivot.
// All elements are unique, Return the minimum element in the array.
// Example:
// [4,5,6,7,0,1,2] → 0

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int findMin(vector<int> &nums){
            int n = nums.size();
            int low = 0, high = n-1;
            int ans = INT_MAX;
            while(low <= high){
                int mid = (low+high)/2;
                //check for min if left half is sorted, if found then store and eliminated that half
                if(nums[low] <= nums[mid]){
                    ans = min(ans, nums[low]);
                    low = mid + 1;
                }
                // else check for min if right half is sorted, if found then store and eliminated that half
                else{
                    ans = min(ans, nums[mid]);
                    high = mid - 1;
                }
            }
            return ans;
        }
};