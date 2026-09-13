// Statement:
// Given a set of processes with their burst times, execute the processes in an order that minimizes the average waiting time.
// Rule: Among the currently available processes, choose the one with the smallest burst time.

// Core Idea:
// Sort / consider processes by arrival time
//         ↓
// Put all available processes in Min-Heap
//         ↓
// Pick process with smallest burst time
//         ↓
// Execute it
//         ↓
// Add newly arrived processes
//         ↓
// Repeat

// Example:
// P1 → Burst = 6
// P2 → Burst = 2
// P3 → Burst = 4
// Order:
// P2 → P3 → P1

#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> burst = {6, 2, 4};

    sort(burst.begin(), burst.end());

    int waiting = 0;
    int totalWaiting = 0;

    for (int i = 0; i < burst.size(); i++) {
        totalWaiting += waiting;
        waiting += burst[i];
    }

    double averageWaiting = (double)totalWaiting / burst.size();

    return 0;
}