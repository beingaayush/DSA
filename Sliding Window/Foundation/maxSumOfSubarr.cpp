// problem:-
// Given an array and an integer k, find the maximum sum of any subarray of size k.
// we have to find maximum possible sum of any subarray of size k

#include <bits/stdc++.h>
using namespace std;
int maxSubarraySum(vector<int> &nums, int k){
    int windowSum = 0;
    //Find window Sum
    for(int i=0; i<k;i++){
        windowSum += nums[i];
    }

    int left = 0;
    int maxSum = windowSum;
    //slide the window
    for(int  right=k; right<nums.size(); right++){
        windowSum += nums[right];  //add 1 right element
        windowSum -= nums[left];   //remove 1 left element
        left++;
        maxSum = max(maxSum, windowSum);
    }
    return maxSum;
}
int main()
{
    vector<int> nums = {2, 1, 5, 1, 3, 2};
    int k = 3;

    cout << maxSubarraySum(nums, k) << endl;
    return 0;
}