// Problem Statement:
// Given the root of a Binary Search Tree (BST), return the minimum absolute difference between values of any two different nodes in the tree.
// Key constraints:
// Nodes are integers
// Tree follows BST property
// At least 2 nodes exist
// What they want:  Find = min∣a−b∣
// for any two nodes a,b in the BST.

// Core idea:
// Inorder → sorted order
// Only check adjacent nodes (prev vs current)
// Track minimum difference globally

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    TreeNode* prev = NULL;
    int ans = INT_MAX;
    void inorder(TreeNode* root){
        if(!root) return;

        inorder(root->left);

        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }
        prev = root;

        inorder(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
    }
};