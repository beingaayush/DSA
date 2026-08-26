#include <iostream>
#include <vector>

using namespace std;

// Directed Graph me edge add karne ka function
void addDirectedEdge(vector<vector<int>>& adj, int u, int v) {
    // Sirf u se v tak rasta hai (u -> v)
    // Isliye sirf u ki list me v ko push karenge
    adj[u].push_back(v);
}

// Graph ko print karne ka function
void printDirectedGraph(const vector<vector<int>>& adj, int V) {
    for (int i = 0; i < V; ++i) {
        cout << i << ':';
        if (adj[i].empty()) {
            cout << "(Dead End)";
        } else {
            for (int neighbor : adj[i]) {
                cout << neighbor << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int V = 4; // Total 4 nodes (0, 1, 2, 3)
    vector<vector<int>> adj(V);

    // Edges direction ke sath add kar rahe hain:
    addDirectedEdge(adj, 0, 1); // 0 -> 1
    addDirectedEdge(adj, 0, 2); // 0 -> 2
    addDirectedEdge(adj, 1, 2); // 1 -> 2
    addDirectedEdge(adj, 2, 3); // 2 -> 3
    addDirectedEdge(adj, 3, 0); // 3 -> 0 (Back to start)

    // Graph print karke dekhte hain directional flow kaisa hai
    printDirectedGraph(adj, V);

    return 0;
}