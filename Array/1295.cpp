// Problem Statement:
// Given an array of integers, return how many numbers contain an even number of digits.

// Example:
// Input: [12, 345, 2, 6, 7896]
// Output: 2
// (12 and 7896 have even digits)

#include <iostream>
#include <vector>
using namespace std;
class Solution{
    public:
        int findNumbers(vector<int> &nums){
            int counteven = 0;
            for(int i=0; i<nums.size(); i++){
                int num = nums[i];
                int digit = 0;
                while(num > 0){
                    num = num/10;
                    digit++;
                }
                if(digit%2 == 0){
                    counteven++;
                }
            }
            return counteven;
        }
};