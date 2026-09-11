#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topoSort(int V, vector<int> adj[]) {

        vector<int> indegree(V, 0);

        // Calculate indegree
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;

        // Nodes with indegree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm = BFS
        while (!q.empty()) {

            int node = q.front();
            q.pop();

            ans.push_back(node);

            for (auto it : adj[node]) {

                indegree[it]--;

                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return ans;
    }
};