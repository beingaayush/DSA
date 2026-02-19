// Problem Statement:-
// Tumhe ek string text di hui hai (sirf lowercase letters).
// Tumhe check karna hai ki is string ke letters use karke tum “balloon” word kitni baar bana sakte ho.
// Condition:
// Har letter utni hi baar use ho sakta hai jitni baar wo string me present hai.
// “balloon” me:
// b → 1 time
// a → 1 time
// l → 2 times
// o → 2 times
// n → 1 time


#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int maxNumberOfBallons(string s){
            int res = INT_MAX;
            unordered_map<char, int> have;
            for(int i=0; i<s.size(); i++){
                have[s[i]]++;
            }
            unordered_map<char, int> need;
            need['b'] = 1;
            need['a'] = 1;
            need['l'] = 2;
            need['o'] = 2;
            need['n'] = 1;
            for(auto i:need){
                char c  =i.first;
                int freqNeed = i.second;
                int freqHave = have[c];
                int times = freqHave/freqNeed;
                res = min(res, times);
            }
            return res;
        }
};