// Problem Statement:
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys strictly less than the node's key.
// The right subtree of a node contains only nodes with keys strictly greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
 

// Core idea:
// we're not just comparing each node with its parent - we're enforcing a valid range (min–max) for every node.

// Each node must satisfy: min < node < max
// For left subtree → range becomes (min, current node)
// For right subtree → range becomes (current node, max)
// Recursively validate all nodes using these constraints
// Summary: Every node must lie within bounds defined by all its ancestors, not just its parent.

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
    public:
        bool solve(TreeNode* root, TreeNode* min, TreeNode* max){
            if(root == NULL) return true;  // valid BST

            if(min != NULL && root->val <= min->val) return false;
            if(max != NULL && root->val >= max->val) return false;

            return solve(root->left, min, root) && solve(root->right, root, max);
        }

        bool isValidBST(TreeNode* root){
            // passed root, min val, max val
            return solve(root, NULL, NULL);
        }
};