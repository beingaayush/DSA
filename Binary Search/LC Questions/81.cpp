// Problem Statement:-
// You are given:
// An integer array nums sorted in ascending order
// The array is rotated at some unknown pivot
// Duplicates are allowed
// You are also given a target.
// 👉 Return true if target exists in the array.
// 👉 Otherwise, return false.

//Core idea:-
// Agar nums[mid] == target → mil gaya.

// Agar nums[low] == nums[mid] == nums[high]
// → duplicates ki wajah se sorted side pata nahi chalega
// → low++ and high--

// Agar left part sorted hai (nums[low] ≤ nums[mid])
// target us range me hai → left search
// warna → right search

// Else right part sorted hoga
// target us range me hai → right search
// warna → left search

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool search(vector<int> &nums, int target){
            int n = nums.size();
            int low = 0, high = n-1;
            while(low <= high){
                int mid = (low+high)/2;
                if(nums[mid] == target) return true;
                //till all 3 are equals shrink the search space
                if(nums[low] == nums[mid] && nums[mid] == nums[high]){
                    low++;
                    high--;
                    continue;
                }
                //is left half sorted?
                if(nums[low] <= nums[mid]){
                    if(nums[low] <= target && target <= nums[mid]){
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                //is right half sorted?
                else{
                    if(nums[mid] <= target && target <= nums[high]){
                        low = mid + 1;
                    }
                    else{
                        high = mid - 1;
                    }
                }
            }
            return false;
        }
};