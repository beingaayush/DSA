// Problem statement
// Given an array nums of size n, find the majority element.
// The majority element is the element that appears more than (n/2) times.
// You can assume the majority element always exists.
// Core idea (Boyer–Moore Voting Algorithm)

#include <bits/stdc++.h>
using namespace std;
int majorityElement(vector<int> &nums){
    int count = 0;
    int el;

    for(int i=0;i<nums.size();i++){
        if(count == 0){
            nums[i] = el;
            count = 1;
        }
        else if(nums[i] == el){
            count++;
        }
        else{
            count--;
        }
    }
    return el;
}
int main(){
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums);
    return  0;
}


//nums = {2,2,1,1,1,2,2}

// | Step | nums[i] | count | el | Action               |
// | ---- | ------- | ----- | -- | -------------------- |
// | 1    | 2       | 0 → 1 | 2  | count was 0 → pick 2 |
// | 2    | 2       | 1 → 2 | 2  | same as el → ++      |
// | 3    | 1       | 2 → 1 | 2  | different → --       |
// | 4    | 1       | 1 → 0 | 2  | different → --       |
// | 5    | 1       | 0 → 1 | 1  | count 0 → pick 1     |
// | 6    | 2       | 1 → 0 | 1  | different → --       |
// | 7    | 2       | 0 → 1 | 2  | count 0 → pick 2     |
