// Problem Statement:
// You are given numCourses courses and a list prerequisites.
// Each pair [a, b] means you must complete course b before taking course a.
// Return an ordering of all courses that satisfies all prerequisites.
// If it is impossible because of a cycle, return an empty array.

// Core Idea:
// Use Kahn's Algorithm (BFS Topological Sort).
// Create an adjacency list: b → a.
// Calculate indegree of every course.
// Put all courses with indegree = 0 into a queue.
// Pop a course, add it to the answer, and reduce the indegree of its neighbors.
// If any neighbor's indegree becomes 0, push it into the queue.
// At the end:
// If ans.size() == numCourses → valid ordering.
// Otherwise → cycle exists, return {}.
// Intuition:
// Jo course kisi aur course par depend nahi karta, usko pehle karo. 
// Phir uske complete hone se jo courses unlock hote hain, unhe queue mein daalo.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        // Create graph
        vector<vector<int>> adj(numCourses);

        for(auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);
        }

        // Calculate indegree
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < numCourses; i++) {
            for(auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Put courses with no prerequisite in queue
        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        // Kahn's Algorithm
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto it : adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // All courses processed = no cycle
        if(ans.size() == numCourses) {
            return ans;
        }

        return {};
    }
};