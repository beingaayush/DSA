// Problem Statement:-
// You are given an integer array cardPoints where each element represents points on a card, and an integer k.
// You can pick exactly k cards from the array.
// In each move, you may take one card from either the beginning or the end of the array.
// Return the maximum score you can obtain by picking k cards.

// arr = [6,2,3,4,7,2,1,7,1] || k = 4

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int maxScore(vector<int>& nums, int k){
        int n = nums.size();
        int leftSum = 0;
        int rightSum = 0;
        int maxSum = 0;
        
        for(int i=0;i<k;i++) leftSum += nums[i];
        maxSum = leftSum;

        int rightIdx = n-1;
        for(int i=k-1;i>=0;i--){
            leftSum -= nums[i];
            rightSum += nums[rightIdx];
            rightIdx--;
            
            maxSum = max(maxSum, leftSum+rightSum);
        }
        return maxSum;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {6,2,3,4,7,2,1,7,1};
    int k = 4;
    cout << sol.maxScore(nums,k);
}