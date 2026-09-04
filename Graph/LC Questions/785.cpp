// Problem Statement:
// You are given an undirected graph with n nodes, where each node is numbered from 0 to n - 1.
// The graph is represented as: graph[i]
// which contains all the nodes that are directly connected to node i.
// You need to determine whether the graph is bipartite.
// A graph is bipartite if you can divide all its nodes into two groups such that:
// No two nodes in the same group are directly connected.
// Example :
// 0 ---- 1
// |      |
// |      |
// 3 ---- 2
// Can divide:
// Group 1: 0, 2
// Group 2: 1, 3

// Every connected pair belongs to different groups.
// So answer: true
// In coding terms, Return:
// true  → graph is bipartite
// false → graph is not bipartite
// Core condition: Adjacent nodes must always have different colors.

// Core Idea:
// BFS/DFS + 2-Coloring
// Har node ko 2 colors me se ek assign karo: 0 or 1.
// Kisi node ke saare neighbors ko opposite color do.
// Agar koi neighbor already colored hai:
// same color → ❌ false
// opposite color → ✅ continue
// Graph disconnected ho sakta hai, isliye har unvisited node se BFS/DFS start karo.
// One-line logic: Adjacent nodes hamesha different colors ke hone chahiye.
// Agar kahin same color ke adjacent nodes mil gaye, graph bipartite nahi hai.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    bool isBipartite(vector<vector<int>> &graph){
        int n = graph.size();
        vector<int> color(n, -1); // Har node ka color store karega || -1 = abhi color nahi kiya || 0  = first color || 1  = second color

        for(int i=0; i<n; i++){
            if(color[i] != -1) continue; // Agar node already colored/visited hai, toh dobara BFS start karne ki zarurat nahi

            queue<int> q;
            q.push(i);    // current node inserted into queue
            color[i] = 0; // starting node assigned with color 0

            while(!q.empty()){
                int node = q.front();
                q.pop();

                // check all the neighbours of current node
                for(int neighbour : graph[node]){
                    // if neighbour isn't coloured
                    if(color[neighbour] == -1){
                        color[neighbour] = 1 - color[node];  // assigned opposite color of curr node to neighbour
                        q.push(neighbour);
                    }
                    // if neighbour is already coloured, and the color is same as of the curr node
                    else if(color[neighbour] == color[node]) return false;
                }
            }
        }
        return true;
    }
};