// Problem Statement:-
// You’re given a list of intervals where each interval is [start, end].
// Some intervals may overlap.
// Your task: merge all overlapping intervals and 
// return the result as a list of non-overlapping intervals that fully cover the same ranges.

// Core Idea:-
// Sort intervals by start time
// Iterate from left to right
// Keep a current interval
// Compare it with the next one
// Two cases only: No overlap || overlap
// Push the last interval.

// NOTE:
// ans.back() ka matlab
// ans.back() = ans ka last merged interval
// Example:
// Agar ans = [[1,6], [8,10]]
// toh ans.back() = [8,10]         //ans.back()[0] = 8  || ans.back()[1] = 10

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;

        // har interval pe loop
        for(int i = 0; i < intervals.size(); i++){

            // agar ans abhi empty hai (pehla interval)
            // ya current interval overlap nahi kar raha last merged se
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                ans.push_back(intervals[i]);
            }
            else{
                // yahan overlap ho raha hai
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }
        return ans;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
    sol.merge(intervals);
}