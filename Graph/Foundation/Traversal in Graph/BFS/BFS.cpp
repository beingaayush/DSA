#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Graph me Edge add karne ka function (Undirected)
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// BFS Traversal Function
vector<int> bfsTraversal(int V, const vector<vector<int>>& adj, int startNode) {
    vector<int> bfsResult;          // Isme hum final path store karenge
    vector<bool> visited(V, false); // Shuruat me koi visited nahi hai (sab false)
    queue<int> q;                   // Queue banayi nodes ko process karne ke liye

    // 1. Starting node ko Queue me dalo aur visited mark karo
    q.push(startNode);
    visited[startNode] = true;

    // 2. Loop tab tak chalega jab tak line khali na ho jaye
    while (!q.empty()) {
        // Queue ke aage khade node ko bahar nikalo
        int currNode = q.front();
        q.pop();
        
        // Is node ko apne answer me add karo
        bfsResult.push_back(currNode);

        // Uske saare padosiyo (neighbors) ko check karo
        for (int neighbor : adj[currNode]) {
            // Agar neighbor visited nahi hai, toh use Queue me dalo
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true; // Visited mark karna mat bhulna!
            }
        }
    }
    return bfsResult;
}

int main() {
    int V = 5; // Total 5 nodes (0 se 4)
    vector<vector<int>> adj(V);

    // Graph ka structure bana rahe hain
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    cout << "Starting BFS from node 0..." << endl;
    vector<int> result = bfsTraversal(V, adj, 0);

    // BFS result print karte hain
    cout << "BFS Traversal Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}