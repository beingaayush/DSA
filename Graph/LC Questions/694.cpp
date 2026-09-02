// Problem Statement:
// Given a binary grid containing 0s and 1s:
// 1 represents land.
// 0 represents water.
// An island is a group of connected 1s.
// Two islands are considered distinct if their shapes are different.
// Islands can be connected only up, down, left, or right. Diagonal cells are not connected.
// Return the number of distinct island shapes in the grid.

// core idea:
// he problem is not asking where an island is located. It is asking what its shape looks like.
// So:
// Traverse every unvisited land cell using DFS.
// For each island, store the coordinates of its cells relative to the starting cell.
// This removes the effect of the island's position in the grid.
// Store each island's coordinate pattern in a set.
// The size of the set gives the number of distinct islands.

// Example :
// Suppose one island is:
// 1 1
// 1 0

// Starting from (2,3):
// (2,3) → (0,0)
// (2,4) → (0,1)
// (3,3) → (1,0)

// So its shape is: {(0,0), (0,1), (1,0)}
// If another island exists somewhere else but produces the same relative coordinates, it has the same shape and is counted only once.
// Key line - vec.push_back({row - i, col - j});
// i, j are the starting coordinates of the island.
// Therefore, the actual position doesn't matter, only the relative shape does.

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis,
             vector<vector<int>> &grid,
             vector<pair<int, int>> &vec,
             int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        // Mark current cell as visited
        vis[row][col] = 1;

        // Store position relative to starting cell
        vec.push_back({row - i, col - j});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};

        for(int k = 0; k < 4; k++) {

            int nrow = row + delrow[k];
            int ncol = col + delcol[k];

            // Check whether the neighbor is valid, unvisited and land
            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               !vis[nrow][ncol] &&
               grid[nrow][ncol] == 1) {

                // Visit the neighboring cell
                dfs(nrow, ncol, vis, grid, vec, i, j);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Keeps track of visited cells
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Stores unique island shapes
        set<vector<pair<int, int>>> st;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Start DFS from every unvisited land cell
                if(!vis[i][j] && grid[i][j] == 1) {

                    vector<pair<int, int>> vec;

                    // Store the shape of this island
                    dfs(i, j, vis, grid, vec, i, j);

                    // Insert shape into set
                    st.insert(vec);
                }
            }
        }

        // Number of unique shapes
        return st.size();
    }
};