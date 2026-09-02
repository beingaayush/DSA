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
    bool isCycle(int V, vector<vector<int>>& adj) {

        vector<int> vis(V, 0);
        queue<pair<int, int>> q;

        q.push({0, -1});
        vis[0] = 1;

        while (!q.empty()) {

            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {

                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                }
                else if (neighbor != parent) {
                    return true;
                }
            }
        }

        return false;
    }
};