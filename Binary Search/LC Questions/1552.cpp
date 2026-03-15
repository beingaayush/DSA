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


// canPlace() :-
// Ye function sirf ek kaam karta hai:
// Check karna ki given distance dist par k cows place ho sakti hain ya nahi.

// Step-by-step :---

// 1️⃣ First cow place karna
// int count = 1;
// int last = stalls[0];

// First cow always first stall par rakh dete hain.
// Isliye count = 1
// last store karta hai last placed cow ka position.

// Example: stalls = [1,2,4,8,9]
// First cow: 1


// 2️⃣ Remaining stalls check karna
// for(int i = 1; i < stalls.size(); i++)
// Ab har next stall check karte hain.

// 3️⃣ Distance condition
// if(stalls[i] - last >= dist)

// Matlab: current_stall_position - last_cow_position >= dist
// Agar required distance mil gaya → cow place kar do.
// Example: dist = 3
// 1 2 4 8 9
// ↑
// last = 1

// Check:
// 2-1 = 1  ❌
// 4-1 = 3  ✅ place cow

// Placement:
// 1   4

// Update:
// count = 2
// last = 4


// 4️⃣ Next placement
// Check again:
// 8-4 = 4  ✅

// Placement:
// 1   4   8

// count = 3


// 5️⃣ Enough cows placed?
// if(count >= k) return true;
// Agar k cows place ho gayi → distance possible hai.


// 6️⃣ Agar pura loop khatam ho gaya
// return false;
// Matlab itni distance maintain karke k cows place nahi ho paayi.