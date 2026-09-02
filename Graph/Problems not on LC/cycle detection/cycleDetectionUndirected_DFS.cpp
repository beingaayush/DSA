// statement:
// Given an undirected graph with V vertices and E edges, determine whether the graph contains a cycle.
// Return true if a cycle exists, otherwise return false.

// Core Idea:
// In an undirected graph, while doing BFS:
// Keep track of every node's parent.
// When visiting a neighbor:
// If it is not visited, mark it visited and store the current node as its parent.
// If it is already visited and it is not the parent of the current node, then a cycle exist
// Why?  -> Suppose: 
// 0 ---- 1
// |      |
// |      |
// 3 ---- 2
// While BFS reaches 2, it may see 3 already visited.
// But 3 is not the parent of 2, meaning there is another path connecting them. Therefore, a cycle exists.

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