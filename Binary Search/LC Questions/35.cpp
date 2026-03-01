// Problem Statement:-
// Tumhe ek sorted array (ascending order) diya hai aur ek target value.
// Tumhe return karna hai:
// Agar target array me mil jaye → uska index
// Agar na mile → jis position par wo insert hoga (sorted order maintain karte hue)

// Important Understanding:---
// Binary search jab fail hota hai (target nahi milta),
// tab low pointer exactly us position pe hota hai jaha target insert hoga.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int searchInsert(vector<int> &nums, int target){
            int low = 0;
            int high = nums.size() - 1;

            while(low <= high){
                int mid = low + (high - low)/2;
                if(target == nums[mid]){
                    return mid;
                }
                else if(target > nums[mid]){
                    low = mid + 1;
                }
                else{
                   high = mid - 1; 
                } 
            }
            return low;
        }
};