// Problem Statement:
// You are given an array nums.
// nums[i] tells you the maximum number of steps you can jump forward from index i.
// Start from index 0 and reach the last index using the minimum number of jumps.
// Return the minimum number of jumps needed.
// Example:
// nums = [2,3,1,1,4]
// Output: 2
// Path:
// 0 → 1 → 4

// Core Idea:
// Think of each jump as covering a range.
// Maintain:
// currentEnd → farthest index reachable with the current number of jumps
// farthest → farthest index we can reach from the current range
// When i == currentEnd, we must make another jump, so:
// jumps++
// currentEnd = farthest
// Simple intuition
// [2, 3, 1, 1, 4]
//   ↑
// Range after 1 jump → indices 0 to 2
// From indices 0,1,2:
// farthest = 4
// So make 2nd jump → reach index 4
// One line: Har current jump ki reachable range ko scan karo, aur us range se maximum next range choose karo.

// Logic:
// farthest → current range se maximum kaha tak ja sakte hain
// currEnd → current jump ki range ka end
// i == currEnd → current jump khatam, next jump lo
// jumps++

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int jumps(vector<int> &nums){
            int jumps = 0, currEnd = 0, farthest = 0;
            for(int i=0; i<nums.size()-1; i++){
                farthest = max(farthest, i+nums[i]);

                if(i == currEnd){
                    jumps++;
                    currEnd = farthest;
                }
            }
            return jumps;
        }      
};