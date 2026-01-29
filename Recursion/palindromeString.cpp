// using functional recursion check whether the string is palindrome or not 
#include <bits/stdc++.h>
using namespace std;

bool fn(int i,string &s){
    if(i>=s.size()/2) return true;                    //then no more will code run (cond full fill ho gya)
    if(s[i] != s[s.size()-i-1]) return false;        //check ki pehla or uska corresponding same h ya nhi
    return fn(i+1,s);                               //otherwise i+1 iterate kro and string return krdo !
}

int main(){
    string s = "MADAM";
    cout << fn(0,s);
    return  0;
}



//another code 
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int left, int right) {
    if(left >= right)
        return true;

    if(s[left] != s[right])
        return false;

    return isPalindrome(s, left + 1, right - 1);
}

int main() {
    string s;
    cin >> s;

    if(isPalindrome(s, 0, s.length() - 1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}
