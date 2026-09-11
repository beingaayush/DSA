// Problem Statement:
// You are given a list of words from an alien language. The words are sorted according to the alien dictionary order.
// You need to determine the order of characters in this alien language.
// Return any valid ordering of the characters.
// If no valid ordering exists, return an empty string.
// Example:
// words = ["wrt", "wrf", "er", "ett", "rftt"]
// Output = "wertf"
// This means: w < e < r < t < f

// Core Idea:
// This is basically Topological Sort + Kahn's Algorithm.

// 1. Compare adjacent words
// Take two consecutive words and find the first character where they differ.
// Example:
// wrt
// wrf
// First difference: t != f
// Therefore: t → f
// Meaning t comes before f.

// 2. Build a directed graph
// For every adjacent pair, add an edge:
// character1 → character2
// Example:
// wrt
// wrf    → t → f

// wrf
// er     → w → e

// er
// ett    → r → t

// ett
// rftt   → e → 
// So we get: w → e → r → t → f

// 3. Calculate indegree
// Count how many characters must come before each character.
// Example:
// w: 0
// e: 1
// r: 1
// t: 1
// f: 1


// 4. Apply Kahn's Algorithm
// Put all characters with:
// indegree = 0
// into a queue.
// Then:
// pop character
// → add it to answer
// → remove its outgoing edges
// → if someone's indegree becomes 0, push it
// Finally, the answer is the topological ordering.

// Important edge case
// If: ["abc", "ab"]
// This is invalid because a longer word cannot come before its exact prefix.
// Return: ""
// Also, if a cycle exists, such as:
// a → b
// b → a
// there is no valid ordering, so return "".

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, int> indegree;

        // Add all characters
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                indegree[words[i][j]] = 0;
            }
        }

        // Build graph
        // Adjacent words compare karo → first different character dhundo → edge banao → bas, break.
        for (int i = 0; i < words.size() - 1; i++) {
            string word1 = words[i];
            string word2 = words[i + 1];

            int len = min(word1.size(), word2.size());
            bool found = false;

            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j]].push_back(word2[j]);
                    indegree[word2[j]]++;
                    found = true;
                    break;
                }
            }

            // Invalid case: ["abc", "ab"]
            if (!found && word1.size() > word2.size()) {
                return "";
            }
        }

        // Kahn's Algorithm
        queue<char> q;

        for (auto it : indegree) {
            if (it.second == 0) {
                q.push(it.first);
            }
        }

        string ans;

        while (!q.empty()) {
            char node = q.front();
            q.pop();

            ans.push_back(node);

            for (char neighbour : adj[node]) {
                indegree[neighbour]--;

                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }
        }

        // Cycle detected
        if (ans.size() != indegree.size()) {
            return "";
        }

        return ans;
    }
};