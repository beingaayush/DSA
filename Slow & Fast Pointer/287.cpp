// Problem Statement:
// You are given an array nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, but it may appear more than once.
// Return the duplicate number

// core idea
// we will treat this array qn like linkedlist, yes this is that few qns of slow & fast pointer
// Move slow by 1 step and fast by 2 steps → they must meet inside the cycle
// Reset slow to start
// Move both one step at a time → the node where they meet again is the duplicate number


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: find entry point
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

int main() {
    vector<int> nums = {1, 3, 4, 2, 2}; // example input
    Solution sol;
    cout << "Duplicate number is: " << sol.findDuplicate(nums) << endl;
    return 0;
}
