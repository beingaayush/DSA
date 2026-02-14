// problem statement:- 
// LeetCode 977 – Squares of a Sorted Array
// Given a sorted array (can have negatives), return a new array of squares of previous array, also sorted.
// 2 methods for this question is described here. | method 1 is Good



//method 1 :-
#include <bits/stdc++.h>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int j = n - 1;
    int idx = n - 1;           // last se element ko rkhnge hum

    vector<int> res(n);

    while (i <= j) {
        if (abs(nums[i]) > abs(nums[j])) {
            res[idx] = nums[i] * nums[i];
            i++;
        } else {
            res[idx] = nums[j] * nums[j];
            j--;
        }
        idx--;
    }
    return res;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};

    vector<int> result = sortedSquares(nums);

    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}




//method 2
#include <bits/stdc++.h>
using namespace std;
void sqre(int arr[], int siz, vector<int> &neg, vector<int> &pos, vector<int> &res){
    for(int i=0;i<siz;i++){
        if(arr[i] < 0){
            neg.push_back(arr[i]);
        }
        else{
            pos.push_back(arr[i]);
        }
    }
    if(neg.size() == 0){ //if only positive element
        for(int i=0;i<pos.size();i++){
            pos[i] = pos[i] * pos[i];
            cout << pos[i] <<" ";
        } 
    }
    if(pos.size() == 0){ //if only negative element
        for(int i=0;i<neg.size();i++){
            neg[i] = neg[i] * neg[i];
            cout << neg[i] <<" ";
        }
        reverse(neg.begin(),neg.end());
    }

    //merge if both negative and positive element found
    int i = 0;
    int j = 0;
    for(int i=0;i<neg.size();i++){
        neg[i] = neg[i]*neg[i];
    }
    reverse(neg.begin(),neg.end());
    for(int i=0;i<pos.size();i++){
        pos[i] = pos[i]*pos[i];
    }
    while(i<neg.size() && j<pos.size()){
        if(neg[i] <= pos[j]){
            res.push_back(neg[i]);
            i++;
        }
        else{
            res.push_back(pos[i]);
            j++;
        }
    }
    while(i<neg.size()){
        res.push_back(neg[i]);
        i++;
    }
    while(j<pos.size()){
        res.push_back(pos[j]);
        j++;
    }
    
}
int main(){
    int siz = 6;
    int arr[siz] = {-4,-2,0,3,4,7};

    vector<int> neg;
    // int n = neg.size();
    vector<int>pos;
    // int m = pos.size();
   
    vector<int> res;
    
    sqre(arr,siz,neg,pos,res);
    for(int i=0;i<res.size();i++) cout<<res[i]<<" ";
    return  0;
}



