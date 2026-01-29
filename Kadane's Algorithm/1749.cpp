// Problem Statement:
// given an array (nums) consists +ve & -ve both
// Return the maximum absolute value of the sum of any subarray.

// core idea:-
// will track -
// • maximum subarray sum (best positive gain)
// • minimum subarray sum (most negative dip)
// Because:
// Large positive sum → large absolute value
// Large negative sum → also large absolute value

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxAbsSubarr(vector<int> &nums){
        int currMaxSum = nums[0];
        int currMinSum = nums[0];
        int maxSum = nums[0];
        int minSum = nums[0];

        for(int i=1; i<nums.size(); i++){
            currMaxSum = max(currMaxSum + nums[i], nums[i]);
            currMinSum = min(currMinSum + nums[i], nums[i]);

            maxSum = max(maxSum, currMaxSum);
            minSum = min(minSum, currMinSum);
        }
        return max(maxSum, abs(minSum));
    }
};

int main(){
    Solution Sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << Sol.maxAbsSubarr(nums);
    return  0;
}