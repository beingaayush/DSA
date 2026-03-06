//Problem Statement:-
// You are given a sorted array where every element appears twice, except one element that appears only once.
// Find that single element.
// Example:
// Input:  [1,1,2,3,3,4,4] | Output: 2
// On above, All numbers appear in pairs except 2, so return 2.

//Core idea:-
// Use binary search.
// Check if mid follows the correct pair pattern:
// Even index → should match with next
// Odd index → should match with previous
// If the pattern is correct, the single element is on the right.
// If the pattern is broken, the single element is on the left.

//BruteForce Solution | Linear search | O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int singleElement(vector<int> &nums){
            int n = nums.size();
            if(n == 1) nums[0];
            for(int i=0; i<n; i++){
                if(i == 0){
                    if(nums[i] != nums[i+1]) return nums[i];
                }
                else if(i == n-1){
                    if(nums[i] != nums[i-1]) return nums[i];
                }
                else{
                    if(nums[i] != nums[i+1] && nums[i] != nums[i-1]) return nums[i]; 
                }
            }
            return -1;
        }
};

//Optimal Solution | Binary Search | O(logn)
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int findSingleElement(vector<int> &nums){
            int n = nums.size();
            if(n == 1) return nums[0];
            if(nums[0] != nums[1]) return nums[0];
            if(nums[n-1] != nums[n-2]) return nums[n-1];

            int low = 1, high = n-2;
            while(low <= high){
                int mid = (low+high)/2;
                if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1]){
                    return nums[mid];
                }
                //means standing on left half and target element is on right half
                if(mid % 2 == 1 && nums[mid] == nums[mid-1]
                || mid % 2 == 0 && nums[mid] == nums[mid+1]){
                    low = mid + 1;
                }
                //means standing on right half and target element is on left half
                else{
                    high = mid - 1;
                }
            }
            return -1;
        }
};