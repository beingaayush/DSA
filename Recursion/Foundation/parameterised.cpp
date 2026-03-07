// sum of n using recursion <-> (parameterised recursion)
#include <bits/stdc++.h>
using namespace std;

void fn(int i, int sum){
    if(i<1){
        cout << sum;
        return;
    }
    fn(i-1,sum+i);
}

int main(){
    int sum = 0;
    int n;
    cout << "enter n: ";
    cin>>n;

    fn(n,sum);

    return  0;
}