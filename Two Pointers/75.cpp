//classic "Dutch National Flag Algorithm" question | //0s come first → then 1s → then 2s
// algo intituition:-
// [0 ... low-1]      → all 0s
// [low ... mid-1]    → all 1s
// [mid ... high]     → unknown
// [high+1 ... end]   → all 2s


//Problem:- 
//You are given an array nums with n elements where each element is 0, 1, or 2,
//representing the colors red, white, and blue respectively.
//rearrange elements without sorting fnx as 0s come first → then 1s → then 2s

#include <bits/stdc++.h>
using namespace std;
void sortColors(vector<int> &nums, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(nums[mid] == 0){
            swap(nums[low],nums[mid]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1){
            mid++;
        }
        else {
            swap(nums[mid],nums[high]);
            high--;
        }
    }
}
int main(){
    vector<int> nums = {2,0,2,1,1,0};
    int n = nums.size();
    sortColors(nums,n);

    for(auto x: nums) cout<<x<<" ";
    return  0;
}
