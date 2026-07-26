//rotating an array by D places.
#include <bits/stdc++.h>
using namespace std;
//BRUTEFORCE SOLUTION

// void rotate(int arr[], int n, int d){
//     d = d%n;
//     //putting d places elements into temp
//     int temp[d];
//     for(int i=0;i<d;i++){
//         temp[i] = arr[i];
//     }

//     //shifting rest elements to left
//     for(int i=d;i<n;i++){
//         arr[i-d] = arr[i];
//     }

//     //putting temp to last
//     int j = 0;
//     for(int i=n-d; i<n; i++){
//         arr[i] = temp[j];
//         j++;
//     }
// }

//OPTIMAL SOLUTION
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        // Handle cases where k > n
        k = k % n;

        // Step 1: Reverse the entire array
        // Example: 1 2 3 4 5 6 7 -> 7 6 5 4 3 2 1
        reverse(nums.begin(), nums.end());

        // Step 2: Reverse the first k elements
        // Example: 7 6 5 -> 5 6 7
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: Reverse the remaining elements
        // Example: 4 3 2 1 -> 1 2 3 4
        reverse(nums.begin() + k, nums.end());
    }
};