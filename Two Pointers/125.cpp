// Problem Statement:-
// Given a string s, determine if it is a palindrome, 
// considering only alphanumeric characters and ignoring cases.

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool isPalindrome( string s){
        int n = s.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            //skipping garbage values(,." "..etc) (isalnum used for it)
            while(left<right && !isalnum(s[left])) left++;
            while(left<right && !isalnum(s[right])) right--;
            //comparing both pointers after switching it into lowercases
            if(tolower(s[left]) != tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};
int main(){
    Solution sol;
    string s = "A man, a plan, a canal: Panama";
    cout << sol.isPalindrome(s);
    return  0;
}