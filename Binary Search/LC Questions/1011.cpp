// Problem Statement:-
// Tumhe ek array weights diya gaya hai jisme weights[i] i-th package ka weight hai.
// Ek ship hai jo daily packages bhejta hai, lekin uski maximum capacity limited hai.
// Rules:
// Packages same order me ship karne padenge (rearrange nahi kar sakte).
// Har din ship me packages load karte rahoge jab tak capacity exceed na ho jaye.
// Agar next package add karne se capacity exceed ho jati hai, to wo package next day jayega.
// Tumhe ek number D diya gaya hai (kitne days me sab packages ship karne hain).
// Task
// Find karo minimum ship capacity jisse saare packages D days ke andar ship ho jayein.


#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int daysRequired(vector<int> &weights, int capacity){
            int day = 1;
            int load = 0;

            for(int i=0; i<weights.size(); i++){
                if(load + weights[i] > capacity){
                    day++;               //ship on next day
                    load = weights[i];  //start new day's load
                }
                else{
                    load += weights[i];  //keep adding in the same day
                }
            }
            return day;
        }
        int findmax(vector<int> &weights){
            int maxi = INT_MIN;
            for(int i=0; i<weights.size(); i++){
                maxi = max(maxi, weights[i]);
            }
            return maxi;
        }
        int sumOfWeights(vector<int> &weights){
            int sum = 0;
            for(int i=0; i<weights.size(); i++){
                sum += weights[i];
            }
            return sum;
        }
        int shipWithinDays(vector<int> &weights, int days){
            int low = findmax(weights);
            int high = sumOfWeights(weights);

            while(low <= high){
                int mid = (low + high)/2;
                if(daysRequired(weights, mid) <= days){
                    high = mid - 1;     //valid, but try smaller capacity 
                }
                else{
                    low = mid + 1;     //not valid, capacity is too small
                }
            }
            return low;
        }
};
