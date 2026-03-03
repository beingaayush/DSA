// Problem Statement:-
// You are given:
// A sorted array (ascending order)
// The array is rotated at some unknown position
// All elements are unique
// You are also given a target.
// 👉 Return the index of target if it exists.
// 👉 If it does not exist, return -1.
// Example:
// nums = [4,5,6,7,0,1,2], target = 0 → Output: 4

//Core idea:-
// Normal binary search directly work nahi karega because array rotated hai.
// Har step pe observe karo:
// Mid nikaalo.
// Check karo:  Kya left half sorted hai?  Ya right half sorted hai?
// Rotation hone ke baad bhi array ka ek half hamesha sorted hota hai.
// Logic Flow:
// Agar left half sorted hai:  Check karo target left range me aata hai ya nahi.
// Agar haan → right hatao.
// Agar nahi → left hatao.
// Agar right half sorted hai: Check karo target right range me hai ya nahi.
// Agar haan → left hatao.
// Agar nahi → right hatao.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int Search(vector<int> &nums, int target){
            int n = nums.size();
            int low = 0, high = n - 1;
            while(low <= high){
                int mid = (low+high)/2;
                if(nums[mid] == target) return mid;
                //left half sorted
                else if(nums[low] <= nums[mid]){
                    if(nums[low] <= target && target <= nums[mid]){
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                //right half sorted
                else{
                    if(nums[mid] <= target && target <= nums[high]){
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
            }
            return -1;
        }
};