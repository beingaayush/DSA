#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);

    dp[0] = 0;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[n];

    return 0;
}



// Tabulation actually kya solve kar raha?
// Memoization ka main problem: recursion baar-baar function calls kar rahi thi.
// Tabulation bolta hai:
// "Recursion hi hata do. Chhote answers pehle calculate karo, phir unhi se bade answers banao."

// So:
// Memoization:
// Top → Bottom
// Recursion + dp

// Tabulation:
// Bottom → Top
// Loop + dp

// Dono ka purpose same hai: repeated calculation avoid karna.
// Generally dono ka time O(n) hai, but tabulation mein recursion stack nahi hota.