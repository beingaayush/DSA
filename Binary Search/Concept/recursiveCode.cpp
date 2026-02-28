#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(vector<int>& nums, int low, int high, int target) {
        // Base case
        if (low > high) {
            return -1;
        }

        int mid = (low + high) / 2;

        // If target found
        if (nums[mid] == target) {
            return mid;
        }
        // Search in right half
        else if (target > nums[mid]) {
            return binarySearch(nums, mid + 1, high, target);
        }
        // Search in left half
        else {
            return binarySearch(nums, low, mid - 1, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size() - 1, target);
    }
};