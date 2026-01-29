// Problem statement :
// Given an integer array nums, find the contiguous subarray that has the largest product, and return that product.
// core idea -
// 👉 negative numbers flip sign
// 👉 a small negative can become huge positive later
// So you must track:
// • max product ending at i
// • min product ending at i
// (both are needed)


#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxProductSubarray(vector<int> & nums){
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int ans = nums[0];

        for(int i=1;i<nums.size(); i++){
            int v1 = maxProduct * nums[i];
            int v2 = minProduct * nums[i];

            maxProduct = max(nums[i], max(v1,v2));
            minProduct = min(nums[i], min(v1,v2));
            ans = max(ans, max(maxProduct, minProduct));
        }
        return ans;
    }
};

int main(){
    Solution Sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Sol.maxProductSubarray(nums);
    return  0;
}