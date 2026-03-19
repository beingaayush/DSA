// Fibonacci ek sequence hai jisme har number = pichle 2 numbers ka sum

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        int fib(int n){
            if(n <= 1) return n;
            int last = fib(n-1);
            int sLast = fib(n-2);
            return last + sLast;
        }
};