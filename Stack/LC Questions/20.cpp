// Problem Statement:-
// You are given a string that contains only these characters:
// (  )  {  }  [  ]
// Your task is to check whether the brackets are used correctly.
// What “used correctly” means:--
// Every opening bracket must have a closing bracket
// The closing bracket must be of the same type
// Brackets must close in the correct order , Also valid - ( { } )

#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    bool validParentheses(string s){
        stack<char> st;
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            //if opening bracket comes
            if(c == '(' || c == '{' || c== '['){
                st.push(c);
            }
            //if closing bracket comes
            else{
                //if closing comes & stack is already empty
                if(st.empty()) return false;

                //check - for each closing is their opening exists in stack at most recent position?
                //if closing doesn't matches with most recent opening
                if( 
                (c == ')' && st.top() != '(') || 
                (c == '}' && st.top() != '{') || 
                (c == ']' && st.top() != '[')
                ){
                    return false;
                }
                //else if closing matches with most recent opening - remove that from stack
                else{
                    st.pop();
                }
            }
        }
        return st.empty();

    }
};
int main(){
    Solution sol;
    string s = "({})";
    sol.validParentheses(s);
    return  0;
}