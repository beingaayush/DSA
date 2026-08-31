// Problem Statement:
// You are given an m × n grid where each cell can contain:
// 0 → Empty cell
// 1 → Fresh orange
// 2 → Rotten orange

// Every minute, a rotten orange makes any fresh orange directly adjacent to it rotten.
// Adjacent means up, down, left, or right. Diagonal oranges are apparently not invited to the party.
// Tas : Return the minimum number of minutes that must elapse until no fresh orange remains.
// If it is impossible for all fresh oranges to become rotten, return -1.
// Example:
// Input:
// [
//   [2,1,1],
//   [1,1,0],
//   [0,1,1]
// ]

// Output:
// 4
// Because the rotting spreads level-by-level, one minute at a time.

// Core Idea:
// The key observation is: All rotten oranges start spreading simultaneously.
// So this is a Multi-Source BFS problem.
// Approach :-
// Put all rotten oranges (2) into a queue initially.
// Count the total number of fresh oranges (1).
// Process the queue level by level.
// One BFS level = 1 minute.
// For every rotten orange, check its 4 directions.
// If a neighboring cell is fresh : Make it rotten.
// Decrease fresh count.
// Push it into the queue.
// Continue until the queue is empty.
// At the end:
// fresh == 0 → return number of minutes.
// fresh > 0 → return -1.

// Why BFS?
// Because BFS processes oranges based on their distance from the initially rotten oranges.
// Minute 0:  2 1 1
//            1 1 0
//            0 1 1

// Minute 1:  2 2 1
//            2 1 0
//            0 1 1

// Minute 2:  2 2 2
//            2 2 0
//            0 1 1
// Each BFS level represents exactly one minute.
// That's the entire trick. Humanity invented BFS so we could efficiently rot oranges. 🍊


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Queue stores: {{row, col}, time}
        queue<pair<pair<int, int>, int>> q;

        // vis[i][j] = 0 -> not visited
        // vis[i][j] = 2 -> visited
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Put all rotten oranges into the queue
        // Their starting time is 0
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        int tm = 0;

        // Directions: up, right, down, left
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        // Multi-source BFS
        while(!q.empty()) {

            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            q.pop();

            // Store maximum time reached
            tm = max(tm, t);

            // Check all 4 neighbours
            for(int i = 0; i < 4; i++) {

                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check:
                // 1. Neighbour is inside the grid
                // 2. Neighbour is a fresh orange
                // 3. Neighbour is not visited yet
                if(nrow >= 0 && nrow < n &&
                   ncol >= 0 && ncol < m &&
                   grid[nrow][ncol] == 1 &&
                   vis[nrow][ncol] == 0) {

                    // Mark the fresh orange as visited
                    vis[nrow][ncol] = 2;

                    // It becomes rotten at time t + 1
                    q.push({{nrow, ncol}, t + 1});
                }
            }
        }

        // BFS is complete.
        // If any fresh orange is still unvisited,
        // it can never become rotten.
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(grid[i][j] == 1 && vis[i][j] == 0)
                    return -1;
            }
        }

        // All oranges have become rotten
        return tm;
    }
};