// Problem Statement:-
// You are given:
// bloomDay[i] → the day the i-th flower blooms
// m → number of bouquets needed
// k → flowers required per bouquet

// Rule:
// A bouquet needs k adjacent flowers.
// A flower can be used only once.

// Goal:
// Find the minimum day when it becomes possible to make m bouquets.
// If impossible → return -1.

// Core idea:-
// Use Binary Search on days:
// Search space: 1 → max(bloomDay)
// For a candidate day mid, check:
// How many bouquets can be formed using flowers that bloom ≤ mid.
// If bouquets ≥ m → try smaller day.
// Else → need more days.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool canMakeBouquet(vector<int> &bloomDay, int m, int k, int day){
            int count = 0;
            int bouquets = 0;
            for(int i=0; i<bloomDay.size(); i++){
                // flower is bloomed by this day
                if(bloomDay[i] <= day){
                    count++;
                }
                //else break in adjacency, make bouquets from counted flowers
                else{
                    bouquets += count/k;
                    count = 0;
                }
            }
            // for last continuous group
            bouquets += count/k;
            return bouquets >= m;
        }
        int minDays(vector<int> &bloomDay, int m, int k){
            long long totalNeeded = 1LL * m * k;
            // not enough flowers
            if(totalNeeded > bloomDay.size()) return -1;
            
            //finding the min, max value/range from the bloomDay(array)
            int mini = INT_MAX;
            int maxi = INT_MIN;
            for(int i=0; i<bloomDay.size(); i++){
                mini = min(mini, bloomDay[i]);
                maxi = max(maxi, bloomDay[i]);
            }
            int low = mini, high = maxi;
            while(low <= high){
                int mid = (low + high)/2;
                if(canMakeBouquet(bloomDay, m, k, mid)){
                    high = mid - 1;  //try smaller day
                }
                else{
                    low = mid + 1;  //need more day
                }
            }
            return low;
        }
};