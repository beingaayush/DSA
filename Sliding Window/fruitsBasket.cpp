// Problem statement:- 
// You’re given an array fruits[] where each element represents a type of fruit on a tree in a row.
// You have two baskets, and each basket can hold only one type of fruit (but unlimited quantity).

// **** we will use unordered_map hashing to store the value and their count/frequency ****
// Maintain a window that contains at most 2 distinct fruit types
// Expand the window to the right (keep collecting fruits)
// If distinct types become more than 2:
// Shrink the window from the left until only 2 types remain
// Track the maximum window size during this process
// 👉 Goal: Return the maximum number of fruits you can collect. | maximum Length return karni hai :)

#include <bits/stdc++.h>
using namespace std;
int fruitsBasket(vector<int> &fruits){
    unordered_map<int,int> mpp;
    int left = 0;
    int maxLen = 0;

    for(int right =0; right<fruits.size(); right++){
        mpp[fruits[right]]++;   //from right pointer add elements inside the hashfunction

        //this loop only runs when we have more than 2 types of elements in the map
        while(mpp.size() > 2){
            mpp[fruits[left]]--;   //remove elements from left
            if(mpp[fruits[left]] == 0){ //Are there no more fruits of this type left in the window?
                mpp.erase(fruits[left]);   //Remove that fruit type completely from the basket.
            }
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }
    return maxLen;
}
int main(){
    vector <int> fruits = {1, 2, 1, 2, 3};
    cout << fruitsBasket(fruits);
    return  0;
}