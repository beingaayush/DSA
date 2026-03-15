// Problem Statement:-
// Given n stall positions and k cows, place the cows in the stalls (one cow per stall) 
// such that the minimum distance between any two cows is maximized.
// Example
// stalls = [1, 2, 4, 8, 9]
// k = 3
// Best placement: 1   4   8
// Distances:
// 4−1 = 3
// 8−4 = 4
// Minimum distance = 3 | Output → 3

// Core idea:
// Sort stalls
// Binary search on minimum distance (1 → max stall gap)
// For each distance greedily place cows from left to right
// If k cows place ho jati hain → distance badhao
// Otherwise distance kam karo

#include <bits/stdc++.h>
using namespace std;
class Solution{
    bool canPlace(vector<int> &stalls, int dist, int cows){
        int cntCows = 1;
        int last = stalls[0];
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - last >= dist){
                cntCows++;
                last = stalls[i];
            }
            if(cntCows >= cows) return true;
        }
        return false;
    }
    int aggressiveCows(vector<int> &stalls, int k){
        int low = 0, high = stalls.back() - stalls.front();
        
        while(low <= high){
            int mid = (low + high )/2;
            if(canPlace(stalls, mid, k) == true){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }       
        }
        return high;
    }    
};