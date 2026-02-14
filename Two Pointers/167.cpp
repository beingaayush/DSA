// problem statement :-
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

// summary - leetCode qn . 167 => index value return krni hai, 1-indexed val.

#include <bits/stdc++.h>
using namespace std;
void twosum(int numbers[], int n, int target){
    int i=0, j = n-1;
    while(i<j){
        int sum = numbers[i] + numbers[j];
        if(sum == target){
            cout << i+1 <<" "<< j+1;
            return;
        }
        else if(sum < target){
            i++;
        }
        else {
            j--;
        }
    }
}
int main(){
    int n = 4;
    int numbers [n] = {2,7,11,15};
    int target = 9;
    twosum(numbers,n,target);
    return  0;
}