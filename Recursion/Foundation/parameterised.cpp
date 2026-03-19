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