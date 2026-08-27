#include <iostream>
#include <vector>

using namespace std;

// Recursive helper function for DFS
void dfsRecursive(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    // Mark current node as visited
    visited[node] = true;
    cout << node << " ";

    // Traverse all adjacent vertices
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsRecursive(neighbor, adj, visited);
        }
    }
}

// Function to handle disconnected graphs
void dfs(int numNodes, const vector<vector<int>>& adj) {
    vector<bool> visited(numNodes, false);

    // Loop through all nodes to cover disconnected components
    for (int i = 0; i < numNodes; ++i) {
        if (!visited[i]) {
            dfsRecursive(i, adj, visited);
        }
    }
    cout << endl;
}

int main() {
    int numNodes = 5;
    vector<vector<int>> adj(numNodes);

    // Example Undirected Graph:
    // 0 - 1, 0 - 2, 1 - 3, 1 - 4
    auto addEdge = [&](int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);

    cout << "DFS Traversal (Recursive): ";
    dfs(numNodes, adj);

    return 0;
}