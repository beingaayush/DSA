#include <iostream>
using namespace std;

void printNum(int n) {
    if (n == 0) return;   // base case

    cout << n << " ";
    printNum(n - 1);      // recursive call
}

int main() {
    printNum(5);
}

//output: 5 4 3 2 1