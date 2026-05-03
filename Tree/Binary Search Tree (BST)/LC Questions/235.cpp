// Problem Statement:
// Given a Binary Search Tree (BST), find the lowest common ancestor (LCA) of two given nodes p and q.
// According to the definition:
// The lowest common ancestor is the lowest node in the tree that has both p and q as descendants (a node can be a descendant of itself).

// Core idea:
// At any node:
// If both p and q < root → go left
// If both > root → go right
// Otherwise → this node is LCA

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
            if(p->val < root->val && q->val < root->val){
                return lowestCommonAncestor(root->left, p, q);
            }
            else if(p->val > root->val && q->val > root->val){\
                return lowestCommonAncestor(root->right, p, q);
            }
            else return root;
        } 
};