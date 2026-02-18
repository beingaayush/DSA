#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    //pre compute
    int hash[256] = {0};             //there're total 256 special characters
    for(int i=0;i<s.size();i++){
        hash[s[i]]++;                //hash[s[i]+1]         
    }

    int q;
    cin>>q;
    while(q--){
        char ch;
        cin>>ch;
        //fetch
        cout << hash[ch] << endl;
    }
    return  0;
}