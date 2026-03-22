#include <bits/stdc++.h>
using namespace std;
void fn(int n){
    if(n<1) return;      //base case: stop when i < 1
    cout << n << endl;
    fn(n-1);
}

int main(){
    int n;
    cout<<"enter n: ";
    cin >> n;
    
    fn(n);  //start printing from n
    return  0;
}