//moving all zeros to end and all non - zeroes elements to front
#include <bits/stdc++.h>
using namespace std;
// void moveZero(int arr[], int  n){
//     //moving non zeroes to temp array
//     vector<int> temp;;
//     for(int i=0;i<n;i++){
//         if(arr[i] != 0){
//             temp.push_back(arr[i]);
//         }
//     }

//     //moving temp to original array
//     int nz = temp.size();
//     for(int i=0;i<nz;i++){
//         arr[i] = temp[i];
//     }

//     //all zeroes to last
//     for(int i=nz;i<n;i++){
//         arr[i] = 0;
//     }

// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     moveZero(arr,n);
//     for(int i=0;i<n;i++) cout<<arr[i]<<" ";
//     return  0;
// }

// Optimal Approach
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        
        for(int j =0;j<n;j++){
            if(nums[j] != 0){
                nums[i] = nums[j];
                i++;
            }
        }
        while(i<n){
            nums[i] = 0;
            i++;
        }
    }
};