// sum of n using recursion <-> (parameterised recursion)
#include <bits/stdc++.h>
using namespace std;

void fn(int n, int sum){
    if(n<1){
        cout << sum;
        return;
    }
    fn(n-1,sum+n);
}

int main(){
    int sum = 0;
    int n;
    cout << "enter n: ";
    cin>>n;

    fn(n,sum);

    return  0;
}


// breakdown:
// fn(5,0)
//  ↓
// fn(4,5)
//  ↓
// fn(3,9)
//  ↓
// fn(2,12)
//  ↓
// fn(1,14)
//  ↓
// fn(0,15) → print