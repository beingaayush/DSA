// Problem Statement:-
// Design a stack that supports:
// push(x)
// pop()
// top()
// getMin() → return minimum element in O(1) time

#include <bits/stdc++.h>
using namespace std;
class MinStack {
    stack<long long> st;   // main stack: normal + encoded values store karega
    long long minim;       // current minimum element track karega

public:
    MinStack() {
        minim = LLONG_MAX; // initially koi element nahi hai, so min infinite set
    }
    
    void push(int val) {
        if(st.empty()){                 // agar stack empty hai
            st.push(val);               // value directly push karo
            minim = val;                // aur wahi minimum hai
        }
        else if(val >= minim){          // agar new value current min se badi ya equal hai
            st.push(val);               // normal value push karo
        }
        else{                           // agar new value current min se chhoti hai
            // encoding step:
            // old minimum ko preserve karne ke liye special value push karte hain
            st.push(2LL * val - minim); // encoded value push
            minim = val;                // ab new value hi new minimum hai
        }
    }
    
    void pop() {
        if(st.empty()) return;          // safety check

        long long n = st.top();         // top element nikalo
        st.pop();                       // remove from stack

        if(n < minim){                  
            // agar top encoded value tha,
            // toh iska matlab hum current minimum ko pop kar rahe hain
            // isliye previous minimum restore karna padega
            minim = 2LL * minim - n;    // decoding formula
        }
    }
    
    int top() {
        if(st.empty()) return -1;       // safety check

        long long n = st.top();         // top value dekho

        if(n >= minim){
            // agar normal value hai
            return (int)n;
        }

        // agar encoded value hai,
        // actual top element current minimum hota hai
        return (int)minim;
    }
    
    int getMin() {
        if(st.empty()) return -1;       // safety check
        return (int)minim;              // current minimum return
    }
};
