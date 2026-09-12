// Problem statement:
// You are selling lemonade for $5.
// Customers come one by one and pay using either:
// $5
// $10
// $20
// Each lemonade costs $5.
// You start with no money.
// For every customer, you must give the exact change needed.
// Return true if you can serve all customers in order, otherwise return false.

// Example
// bills = [5,5,5,10,20]
// $5 → no change
// $5 → no change
// $5 → no change
// $10 → give back $5
// $20 → give back $10 + $5
// So answer = true.

// Core idea:
// Maintain how many $5 and $10 notes you have, and whenever a $20 comes,
// give change using the best available combination.

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool lemonadeChange(vector<int>& bills){
        int five = 0, ten = 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5) five += 1;
            else if(bills[i] == 10){
                if(five){
                    five -= 1;
                    ten += 1;
                }
                else return false;
            }
            else{ // bills[i] == 20
                if(ten && five){
                    five -= 1;
                    ten -= 1;
                }
                else if(five >= 3){
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};