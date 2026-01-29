#include <bits/stdc++.h>
using namespace std;
void fn(int i, int n){
    if(i>n) return;      //base case: stop when i > n
    cout << i << endl;
    fn(i+1,n);
}

int main(){
    int n;
    cout<<"enter n: ";
    cin >> n;
    fn(1,n);            //start printing from 1
    return  0;
}