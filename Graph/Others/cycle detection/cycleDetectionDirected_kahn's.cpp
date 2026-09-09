// Detect a cycle in a graph using bfs:
// For a directed graph, cycle detection using BFS = Kahn’s Algorithm (Topological Sort).

// Core idea:
// Calculate indegree of every node.
// Put all nodes with indegree == 0 into a queue.
// BFS:
// Remove node.
// Reduce indegree of its neighbours.
// If any neighbour becomes 0, push it.
// Count how many nodes were processed.
// If count != V → cycle exists.

#include <bits/stdc++.h>
using namespace std;

bool isCycle(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);

    // Calculate indegree
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;

    // Nodes with 0 indegree
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;

    // BFS (Kahn's Algorithm)
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        count++;

        for (auto it : adj[node]) {
            indegree[it]--;

            if (indegree[it] == 0)
                q.push(it);
        }
    }

    // Not all nodes processed = cycle
    return count != V;
}