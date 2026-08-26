#include <iostream>
#include <vector>

using namespace std;

// Graph me edge (rasta) add karne ka function
void addEdge(vector<vector<int>>& adj, int u, int v) {
    // Kyuki graph undirected hai, toh u se v aur v se u dono raste banenge
    adj[u].push_back(v);
    adj[v].push_back(u); 
}

// Graph ko print karne ka function
void printGraph(const vector<vector<int>>& adj, int V) {
    for (int i = 0; i < V; ++i) {
        cout << "Node " << i << " ke padosi (neighbors) hai: ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5; // Graph me total 5 nodes hain (0 se lekar 4 tak)
    
    // 5 size ka 2D vector banaya jahan har row ek list hai
    vector<vector<int>> adj(V);

    // Edges add kar rahe hain (Connections bana rahe hain)
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

    // Graph ko print karke dekhte hain kaisa dikhta hai
    printGraph(adj, V);

    return 0;
}