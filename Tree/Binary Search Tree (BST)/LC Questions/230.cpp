// Problem Statement:
// You’re given the root of a Binary Search Tree (BST) and an integer k.
// Return the k-th smallest value among all nodes (1-indexed).

// Core idea:
// Optimal approach: In-order traversal + counter
// Traverse left subtree first (smallest elements)
// Maintain a global counter (prevOrder) to track how many nodes you've visited
// At each node:
// Check → prevOrder + 1 == k
// if yes → current node is the k-th smallest, return immediately
// Otherwise → increment prevOrder
// Then move to right subtree
// Use -1 as a signal to propagate the answer up the recursion stack

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
    public:
        int kthSmallest(TreeNode* root, int k){

        }
};