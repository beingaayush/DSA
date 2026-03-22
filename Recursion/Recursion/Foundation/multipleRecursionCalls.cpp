// multiple recursion calls - fabonacci number
#include <bits/stdc++.h>
using namespace std;

int fn(int n){
    if(n<=1) return n;
    int last = fn(n-1);
    int slast = fn(n-2);
    return last + slast;
}

int main(){
    int n;
    cout<<"enter index number for which u want fabonacci = ";
    cin>>n;
    cout<<fn(n);
    return  0;
}