// Problem Statement:-
// You are given a number x.
// Return the square root of x, but only the integer part.
// If the square root is not an integer, ignore the decimal part.
// Examples
// x = 4 → answer = 2 (because √4 = 2)
// x = 8 → answer = 2 (because √8 = 2.828… → take only 2)
// x = 15 → answer = 3 (because √15 = 3.87… → take 3)
// One-line understanding - Find the largest number whose square is ≤ x.

// Note - long long is used to prevent overflow when computing mid * mid,
// since the result can exceed the int limit.

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int mySqrt(int x){
            long long low = 0;
            long long high = x;
            long long ans = 0; // stores the best possible answer

            while(low <= high){
                long long mid = (low + high)/2;
                // if mid^2 is valid (not exceeding x)
                if(mid * mid <= x){
                    ans = mid;             // store it as possible sqrt
                    low = mid + 1;        // try to find a bigger valid number
                }
                //else mid^2 too big → move left
                else{
                    high = mid - 1;
                }
            }
            return ans;

        }
};