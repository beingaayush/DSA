// Problem Statement:-
// You are given a binary array nums (containing only 0s and 1s) and an integer k.
// You can flip at most k zeros to ones.
// Return the maximum number of consecutive 1s in the array after flipping at most k zeros.

#include <bits/stdc++.h>
using namespace std;
int maxConsecutive(vector<int> &nums, int k){
    int n = nums.size();
    int maxLen = 0;
    int zeroes = 0;
    int left = 0;
    
    for(int right=0;right<n;right++){
        if(nums[right] == 0) zeroes++;
        if(zeroes > k){
            if(nums[left]==0) zeroes--;
            left++;
        }
        maxLen = max(maxLen, right-left+1);
    }
    return maxLen;
}
int main(){
    vector <int> nums = {1,1,1,0,0,1,1,1,0,1,1,0};
    int k = 2;
    cout << maxConsecutive(nums,k);
    return  0;
}