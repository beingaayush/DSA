#include <bits/stdc++.h>
using namespace std;
void fn(int i, int n){
    if(i<1) return;      //base case: stop when i < 1
    cout << i << endl;
    fn(i-1,n);
}

int main(){
    int n;
    cout<<"enter n: ";
    cin >> n;
    fn(n,n);  //start printing from n
    return  0;
}