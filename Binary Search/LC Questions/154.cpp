// Problem Statement:-
// You are given a sorted array that has been rotated, and the array may contain duplicate elements.
// Find and return the minimum element in the array.
// Example:
// nums = [2,2,2,0,1] | Output = 0

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
                //if left part is strictly sorted
                if(nums[low] < nums[mid]){
                    ans = min(ans, nums[low]);
                    low = mid + 1;
                }

                //if right part is strictly sorted
                else if(nums[mid] < nums[high]){
                    ans = min(ans, nums[mid]);
                    high = mid - 1;
                }

                //duplicate case
                else{
                    ans = min(ans, nums[low]);
                    low++;
                }
            }
            return ans;
        }

};