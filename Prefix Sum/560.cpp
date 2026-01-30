// Problem Statement:-
// You’re given an integer array nums and an integer k.
// Count how many continuous subarrays have sum exactly equal to k.
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int subarrSumK(vector<int> & nums, int k){
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        int prefixSum = 0, count = 0;
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            // if current sum - k have seen earlier, then increase count
            int remove = prefixSum - k;
            count += mpp[remove];
            //also storing/updating prefixSum for future
            mpp[prefixSum]++;
        }
        return count;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {1,2,3};
    int k = 3;
    cout << sol.subarrSumK(nums,k);
    return  0;
}