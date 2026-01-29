// sum of n using recursion <-> (functional recursion)
#include <bits/stdc++.h>
using namespace std;

int sum(int n){
    if(n==0) return 0;
    return n + sum(n-1);
}

int main(){
    int n;
    cout<<"enter n: ";
    cin>>n;
    cout<<sum(n);
    return  0;
}