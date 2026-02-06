// Problem Statement:-
// Tumhe do lists di jaati hain:
// firstList  = [ [start1, end1], [start2, end2], ... ]
// secondList = [ [startA, endA], [startB, endB], ... ]
// Conditions:-
// Har list ke intervals sorted hain OR aapas me overlap nahi karte

// Task:
// Dono lists ke beech jitne bhi overlapping (intersection) intervals bante hain unko return karni hai.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;

        while (i < firstList.size() && j < secondList.size()) {

            // check overlap
            if (firstList[i][1] >= secondList[j][0] &&
                firstList[i][0] <= secondList[j][1]) {

                int start = max(firstList[i][0], secondList[j][0]);
                int end   = min(firstList[i][1], secondList[j][1]);

                res.push_back({start, end});
            }

            // move the interval which ends first
            if (firstList[i][1] < secondList[j][1])
                i++;
            else
                j++;
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> firstList = {{0,2}, {5,10}, {13,23}, {24,25}};
    vector<vector<int>> secondList = {{1,5}, {8,12}, {15,24}, {25,26}};
    sol.intervalIntersection(firstList, secondList);
    return 0;
}
