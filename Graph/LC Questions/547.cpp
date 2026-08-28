// Problem Statement:-
// You are given an n × n adjacency matrix isConnected, where:
// isConnected[i][j] == 1 means city i and city j are directly connected.
// isConnected[i][j] == 0 means they are not directly connected.
// A province is a group of cities that are directly or indirectly connected.
// Task:
// Return the total number of provinces.
// Example -
// isConnected = [
//   [1,1,0],
//   [1,1,0],
//   [0,0,1]
// ]
// City 0 ↔ City 1 → one province
// City 2 alone → another province
// Answer = 2 provinces

// Core idea:
// Input isConnected Adjacency Matrix me diya hai.
// Pehle usko Adjacency List adjLs me convert karte hain.
// vis array se track karte hain ki kaunsi city visit ho chuki hai.
// Har node ko check karo:
// Agar already visited hai → skip.
// Agar unvisited hai → iska matlab ek naya province mila, so provinces++.
// Us node se DFS chalao aur us province ki directly/indirectly connected saari cities visit kar do.
// Finally, jitni baar DFS kisi unvisited node se start hui, utne hi provinces hain.

#include <bits/stdc++.h>
using namespace std;
class Solution{
private:
    void dfs(int node, vector<int> adj[], vector<bool> &vis){
        vis[node] = true;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }    
public:
    int findCircleNum(vector<vector<int>>& isConnected){
        int n = isConnected.size();

        // convert matrix -> adjacency list
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> vis(n, false);
        int provinces = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                provinces++;
                dfs(i, adj, vis);
            }
        }
        return provinces;
    }
};