// Problem Statement:
// You are given a 2D grid grid consisting of:
// '1' → Land
// '0' → Water
// An island is a group of connected land cells ('1') connected horizontally or vertically.
// Return the number of islands in the grid.
// Example:
// Input:
// [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]

// Output:
// 3
// WHY 3? : There are 3 separate groups of land:

// 1 1 0 0 0
// 1 1 0 0 0   → Island 1

// 0 0 1 0 0   → Island 2

// 0 0 0 1 1   → Island 3

// Core idea:
// Count how many times you start a DFS/BFS from an unvisited land cell '1'.
// Traverse the entire grid.
// If you find '1':
// This is a new island → count++
// Run DFS/BFS from it.
// During DFS/BFS, visit all connected '1' cells and mark them as visited.
// Continue scanning the grid.
// Final count = number of islands.


#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    void dfs(int row, int col,
             vector<vector<bool>>& visited,
             vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Out of grid boundary
        if (row < 0 || row >= rows || col < 0 || col >= cols)
            return;

        // Already visited or water
        if (visited[row][col] || grid[row][col] == '0')
            return;

        // Mark current land as visited
        visited[row][col] = true;

        // Visit all 4 directions
        dfs(row + 1, col, visited, grid); // Down
        dfs(row - 1, col, visited, grid); // Up
        dfs(row, col + 1, visited, grid); // Right
        dfs(row, col - 1, visited, grid); // Left
    }

public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Keeps track of visited cells
        vector<vector<bool>> visited(
            rows, vector<bool>(cols, false)
        );

        int count = 0;

        // Traverse the entire grid
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {

                // Found an unvisited land = new island
                if (!visited[row][col] && grid[row][col] == '1') {
                    count++;

                    // Visit the complete island
                    dfs(row, col, visited, grid);
                }
            }
        }

        return count;
    }
};