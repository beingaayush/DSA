// statement:
// Given an undirected graph with V vertices and E edges, determine whether the graph contains a cycle.
// Return true if a cycle exists, otherwise return false.

// Core Idea:
// 1. Node ko visited mark karo
// 2. Neighbours dekho
// 3. Unvisited → DFS mein jao
// 4. Visited + parent nahi → CYCLE

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    bool dfs(int node, int parent, vector<int>& vis,
             vector<vector<int>>& adj) {

        vis[node] = 1;

        for (int neighbor : adj[node]) {

            // If neighbor is not visited
            if (!vis[neighbor]) {

                if (dfs(neighbor, node, vis, adj))
                    return true;
            }

            // Already visited and not parent
            else if (neighbor != parent) {
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& adj) {

        vector<int> vis(V, 0);

        // For disconnected graph
        for (int i = 0; i < V; i++) {

            if (!vis[i]) {

                if (dfs(i, -1, vis, adj))
                    return true;
            }
        }

        return false;
    }
};