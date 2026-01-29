// Problem Statement:
// Write an algorithm to determine whether a number n is a happy number.
// A number is called happy if the following process eventually ends in 1:
// Start with any positive integer.
// Replace the number by the sum of the squares of its digits.
// Repeat the process.
// If this process results in 1, return true.
// If it enters a cycle that does not include 1, return false.

#include <iostream>
using namespace std;

// Function to calculate sum of squares of digits
int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int d = n % 10;
        n = n / 10;
        sum += d * d;
    }
    return sum;
}

// Function to check if a number is happy
bool isHappy(int n) {
    int slow = n, fast = n;

    do {
        slow = sumOfSquares(slow);
        fast = sumOfSquares(sumOfSquares(fast));

        if (slow == fast && slow != 1) 
            return false;
    } while (fast != 1);

    return true;
}

int main() {
    int n;
    cout << "Enter a number to check if it is happy: ";
    cin >> n;

    if (isHappy(n))
        cout << n << " is a Happy Number!" << endl;
    else
        cout << n << " is NOT a Happy Number!" << endl;

    return 0;
}
