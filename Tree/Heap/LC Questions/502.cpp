// Problem Statement:
// given:
// k = maximum number of projects jo tum complete kar sakte ho
// w = initial capital
// profits[i] = project i complete karne ke baad milne wala profit
// capital[i] = project i start karne ke liye required minimum capital

// Tum maximum k projects complete kar sakte ho.
// Project complete karne ke baad:
// w = w + profits[i]
// Return karo maximum final capital.

// Core Idea :

// Har turn par:
// Dekho kaunse projects current capital w se affordable hain:
// capital[i] <= w
// Available projects me se maximum profit wala project choose karo.
// Uska profit current capital me add karo.
// Ye process maximum k times repeat karo.
// Optimal Approach
// Har project ko {capital, profit} pair ke form me store karo.
// Projects ko required capital ke according sort karo.
// Pointer i use karke jitne projects current capital se affordable hain, unke profits max-heap me daalo.
// Max-heap ke top par maximum profit hoga.
// Us profit ko w me add karo aur process repeat karo.
// Projects ko capital ke according sort karo
//                 ↓
// Jitne projects affordable hain
// unke profits Max Heap me daalo
//                 ↓
// Maximum profit wala project choose karo
//                 ↓
// w += profit
//                 ↓
// Repeat k times

// Time Complexity: O(n log n + k log n)
// Space Complexity: O(n)


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        // Min-heap: {required capital, profit}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> minHeap;

        // Max-heap: available profits
        priority_queue<int> maxHeap;

        int n = profits.size();

        // Store all projects
        for (int i = 0; i < n; i++) {
            minHeap.push({capital[i], profits[i]});
        }

        // Perform at most k projects
        while (k--) {

            // Add all currently affordable projects
            while (!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }

            // No project can be done
            if (maxHeap.empty()) break;

            // Choose maximum profit project
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};