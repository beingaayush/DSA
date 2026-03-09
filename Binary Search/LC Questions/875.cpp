// Problem Statement:-
// You are given an array piles, where each element represents the number of bananas in a pile.
// Koko can eat k bananas per hour.
// Each hour she chooses one pile and eats up to k bananas from it.
// If the pile has fewer than k bananas, she eats the whole pile.
// Koko has h (target) hours to finish all the bananas.
// Find the minimum integer k such that Koko can eat all bananas within h hours. 🍌

// NOTE:-
// ceil = ceiling function.
// Matlab: fraction ko next integer tak round up karna.

// Examples:-
// ceil(2.1) → 3
// ceil(3.0) → 3
// ceil(4.7) → 5

// Is problem me:
// ceil(bananas / k) = ek pile finish karne me kitne hours lagenge.
// Example:-
// pile = 10, speed = 3
// 10 / 3 = 3.33 → ceil = 4 hours

// Code me bina function ke isko aise likhte hain:
// (bananas + k - 1) / k
// Example:-
// (10 + 3 − 1) / 3 = 12 / 3 = 4.


#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    //finding max element from the array | for the last range declaration
        int FindMax(vector<int> &piles){
            int n = piles.size();
            int maxi = INT_MIN;
            for(int i=0; i<n; i++){
                max(maxi, piles[i]);
            }
            return maxi;
        }
        //main func
        int minEatingSpeed(vector<int> &piles, int h){
            int n = piles.size();
            int low = 1;                    // Minimum possible speed is 1 banana/hour
            int high = FindMax(piles);     // Maximum possible speed is the largest pile

            while (low <= high)
            {
                int mid = (low + high)/2;
                //calculating total hours
                long long totalHours = 0;
                for(int i =0; i<n; i++){
                    totalHours += ceil(double(piles[i]) / mid);
                }
                // If Koko can finish within h hours / within target hour
                if(totalHours <= h){
                    // This speed works, try smaller speed
                    high = mid - 1;
                }
                else{
                    // Too slow, increase the speed
                    low = mid + 1;   // need faster speed
                }
            }
            return low;  // 'low' will be the minimum valid eating speed
        }
};