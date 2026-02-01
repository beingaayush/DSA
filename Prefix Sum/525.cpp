// Problem Statement:-
// given a binary array nums (only 0s and 1s).
// Return the maximum length of a contiguous subarray that contains equal number of 0s and 1s.
// Core idea - 
// Treat 0 as -1 and 1 as 1
// Compute a running prefix sum
// If the same prefix sum appears again, the subarray between them has equal 0s and 1s

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxLenSubarr(vector<int> & nums){
       if(nums.size() == 0) return 0;
       unordered_map<int,int> mpp;
       mpp[0] = -1;
       int prefix = 0;
       int maxLen = 0;

       for(int i=0;i<nums.size(); i++){
        if(nums[i] == 0) nums[i] = -1;
        prefix += nums[i];
        //if prefix is seen in the map, then updte subarr len as ("curr idx - where prefix seen" distance)
        if(mpp.find(prefix) != mpp.end()){
            maxLen = max(maxLen, i - mpp[prefix]);
        }
        else{
            mpp[prefix] = i;
        }
       }
       return maxLen;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {0,1,0,1,1,1,0,0};
    cout << sol.maxLenSubarr(nums);
    return  0;
}