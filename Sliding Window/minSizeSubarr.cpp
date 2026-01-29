// problem:- Given an array of positive integers and a target,
// find the minimum length subarray whose sum ≥ target.

#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen (int target, vector<int> &nums){
    int n = nums.size();
    int low = 0;
    int minLen = INT_MAX;
    int sum = 0;
    for(int high = 0; high<n; high++){
        sum += nums[high];
        
        while(sum >= target){
            minLen = min(minLen,high-low+1);        //length = end-start+1
            sum -= nums[low];
            low++;
        }
    }
    return (minLen == INT_MAX) ? 0: minLen;

}
int main()
{
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;

    int result = minSubArrayLen(target, nums);
    cout << "Minimum subarray length: " << result << endl;

    return 0;
}