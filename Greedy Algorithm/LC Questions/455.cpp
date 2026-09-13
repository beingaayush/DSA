// Problem Statement:-
// Tumhare paas greed(childern) aur cookies hain.
// Har child ka ek number hota hai → greed factor
// (child tabhi khush hoga jab cookie ka size us number se barabar ya bada ho)
// Rules:
// Ek child ko sirf ek cookie mil sakti hai
// Ek cookie sirf ek child ko di ja sakti hai
// Task:
// Maximum kitne children ko khush (satisfy) kiya ja sakta hai, ye batana hai.

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int assignCookies(vector<int> &greed, vector<int> &cookies){
        int i = 0, j = 0;
        sort(greed.begin(), greed.end());
        sort(cookies.begin(), cookies.end());

        while(i < greed.size() && j < cookies.size()){
            //child only satisfy when equal OR more cookie than his greed can assigned
            if(greed[i] <= cookies[j]){
                i++;
            }
            j++;
        }
        return i;
    }
};
int main(){
    Solution sol;
    vector<int> greed = {1,2,3};
    vector<int> cookies = {1,1};
    int result = sol.assignCookies(greed, cookies);
    cout << result;
    return  0;
}