// Problem Statement
// You are given an array height[].
// Each element represents the height of a building.
// Each building has width = 1.
// After rain, water gets trapped between buildings.
// 👉 You need to calculate how much total water is trapped.

// core idea:

//        Left building      Right building
//           3               10


// Water level kabhi 3 se upar nahi ja sakta, kyunki left chhota hai.
// Bas. Ye hi pura logic hai.

// Step Flow 
// While left < right:
// Compare height[left] and height[right]
// Move the smaller side
// Update that side ka max       
// Add water if possible


#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int trap(vector<int> &height){
            int n = height.size();
            int left = 0;
            int right = n-1;
            int leftmax = 0, rightmax = 0;
            int water = 0;

            while(left < right){             
                //Jo side chhoti hogi, wahi water decide karegi   
                if(height[left] < height[right]){ 
                    // Agar current height badi hai ya equal hai leftmax se toh naya boundary banega
                    if(height[left] >= leftmax){
                        leftmax = height[left];
                    }
                    else{
                        // Yahan water trap hoga
                       // Kyunki leftmax bada hai current height se
                        water += leftmax - height[left];
                    }
                    left++;
                }
                else{ //same logic for right side
                    if(height[right] >= rightmax){
                        rightmax = height[right];
                    }
                    else{
                        water += rightmax - height[right];
                    }
                    right--;
                }
            }
            return water;
        }
};