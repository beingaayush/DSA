// Problem statement (short):
// Given an array nums and an integer target, return the number of triplets (i, j, k) such that
// i < j < k and
// nums[i] + nums[j] + nums[k] < target. || sum < target
// nums = [-2, 0, 1, 3]
// target = 2
// 👉 Important:
// It’s NOT asking for the triplets themselves
// It asks for the count of such triplets


#include <bits/stdc++.h>
using namespace std;
int threeSumSmaller(vector<int> &nums, int target){
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int count = 0;
    for(int i=0;i<n-2;i++){
        int j = i+1;
        int k = n-1;

        while(j<k){
            int sum = nums[i]+nums[j]+nums[k];
            if(sum == target){
                j++;
                k--;
            }
            else if(sum < target){
                count = count + (k-j);
                j++;
            }
            else if(sum > target){
                k--;
            }
        }
    }
    return count;
}
int main(){
    vector<int> nums = {-2, 0, 1, 3};
    int target = 2;
    cout << threeSumSmaller(nums,target);
    return  0;
}