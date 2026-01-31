// Problem Statement:-
// You’re given a character array s.
// Reverse it in-place

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    void reverseString(string& s){
        int left = 0;
        int right = s.size() - 1;

        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
int main(){
    Solution sol;
    string s = "hello";
    sol.reverseString(s);
    return  0;
}