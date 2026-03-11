// Tumhe ek integer array nums diya gaya hai aur ek number threshold diya gaya hai.

// Tumhe ek positive divisor d choose karna hai.

// For each element of the array: value = ceil(nums[i] / divisor)
// Phir sab values ka sum nikalte ho.

// Condition:
// sum ≤ threshold
// Task -> Aisa smallest divisor find karo jisse (sum) threshold se zyada na ho.

// Example - nums = [1,2,5,9] | threshold = 6
// Try divisor = 5

// ceil(1/5) = 1
// ceil(2/5) = 1
// ceil(5/5) = 1
// ceil(9/5) = 2

// sum = 5  ≤ 6
// Isse chhota divisor try karoge to sum threshold se bada ho jayega.
// Answer = 5.

// Core idea:-
// Bada divisor se divide karo → sum chota hoga
// Chota divisor se divide karo → sum bada hoga
// Bas itna puchhna hai:
// Sabse chota kaun sa number hai jisse sum ≤ threshold ho?
// 1 to max(nums) tak try karo — aur kyunki pattern monotonic hai (sum hamesha ghatta hai jaise divisor badhta hai),
// binary search lagao instead of linear search.

// Search space: 1 to max(nums)
// 1 se chota jaana possible nahi
// aur max(nums) se bada jaana wasteful hai — kyunki tab har element 1 ban jaata hai, sum = n, aur usse chota ho hi nahi sakta.
// Toh answer max(nums) ke andar hi milega guaranteed.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        //finding max range of the array 
        int findMax(vector<int> &nums){
            int maxi = INT_MIN;
            for(int i=0; i<nums.size(); i++){
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }
        //calculating sum of all elements of nums after dividing them with divisor 
        int totalSum(vector<int> &nums, int divisor){
            int sum = 0;
            for(int i=0; i<nums.size(); i++){
                sum += ceil(double(nums[i]) / double(divisor));
            }
            return sum;
        }
        int smallestDivisor(vector<int> &nums, int threshold){
            int low = 1, high = findMax(nums);
            while(low <= high){
                int mid = (low + high)/2;
                if(totalSum(nums, mid) <= threshold){
                    high = mid - 1;    //valid, but try smaller than this
                }
                else{
                    low = mid + 1;
                }
            }
            return low;
        }
};