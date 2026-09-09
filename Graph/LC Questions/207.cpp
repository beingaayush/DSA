// Problem Statement:
// You are given numCourses courses numbered from 0 to numCourses - 1.
// You are also given: prerequisites[i] = [a, b]
// This means you must complete course b before course a.
// Return true if you can finish all courses, otherwise return false.

// Example:
// numCourses = 2
// prerequisites = [[1,0]]

// Order: 0 → 1
// So answer is true.

// If: prerequisites = [[1,0],[0,1]]
// Then: 0 → 1 → 0
// There is a cycle, so answer is false.

// Core Idea :

// Use Kahn's Algorithm (BFS) to detect a cycle in the directed graph.

// Create a directed graph from prerequisites.
// Calculate the indegree of every course.
// Put all courses with indegree = 0 into the queue.
// Remove them one by one and reduce the indegree of their connected courses.
// If any course's indegree becomes 0, add it to the queue.
// Count how many courses were processed.
// Final check
// return cnt == numCourses;
// cnt == numCourses → No cycle → true
// cnt < numCourses → Cycle exists → false
// One-line intuition:
// Courses with no prerequisites are taken first; if eventually every course can be processed, there is no cycle.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
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

        int cnt = 0;

        // Kahn's Algorithm
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            cnt++;

            for(auto it : adj[node]) {
                indegree[it]--;

                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // All courses processed = no cycle
        return cnt == numCourses;
    }
};