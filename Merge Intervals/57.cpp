// Problem statement:-
// ek array diya hai (arr) jisme:
// • intervals sorted hain by start time
// • koi bhi interval overlap nahi karta
// Aur ek newInterval diya gaya hai - interval

// goal:
// newInterval ko intervals me insert karo
// Aur jahan overlap ho — merge karke final list return karo


#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int>> insertIntervals(vector<vector<int>> &arr, vector<int> &interval){
        vector<vector<int>> res;
        int i = 0;
        int n = arr.size();
        while(i<n && arr[i][1] < interval[0]){
            res.push_back(arr[i]);
            i++;
        }
        //if overlaps
        //(this loop is came cause above loop doesn't satisfied and here overlapping is happening)
        while(i<n && arr[i][0] <= interval[1]){
            interval[0] = min(interval[0], arr[i][0]);
            interval[1] = max(interval[1], arr[i][1]);
            i++;
        }
        res.push_back(interval);
        //edge case
        while(i<n){
            res.push_back(arr[i]);
            i++;
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<vector<int>> arr = {{1,3}, {6,9}};
    vector<int> interval = {2,5};
    sol.insertIntervals(arr, interval);
    return  0;
}