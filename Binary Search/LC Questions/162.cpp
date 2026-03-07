// Problem Statement :-
// You are given an integer array nums.
// A peak element is an element that is strictly greater than its neighbors.
// Formally: nums[i-1] < nums[i] > nums[i+1]
// Return the index of any peak element.
// If the array contains multiple peaks, return the index of any one of them.


#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int peakElement(vector<int> &nums){
            int n = nums.size();
            if(n == 1) return 0;
            if(nums[0] > nums[1]) return 0;
            if(nums[n-1] > nums[n-2]) return n-1;

            int low = 1, high = n-1;
            while (low <= high)
            {
                int mid = (low + high)/2;
                //if mid is peak
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                    return mid;
                }
                // else if (this case) then peak is in right half
                else if(nums[mid] > nums[mid-1]){
                    low = mid + 1;
                }
                //else the peak is in left half
                else{
                    high = mid - 1;
                }
            }
            return -1;
        }
};