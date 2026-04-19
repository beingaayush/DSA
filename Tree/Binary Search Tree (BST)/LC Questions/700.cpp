// Problem Statement: 
// You are given the root of a Binary Search Tree (BST) and an integer val.
// Find the node in the BST whose value equals val and return the subtree rooted at that node.
// If such a node exists → return that node (i.e., pointer/reference to it)
// If it does not exist → return NULL
// Key constraint: - BST property holds → left < root < right
// Example:
// Input: root = [4,2,7,1,3], val = 2 | Output:  [2,1,3]
// Input: root = [4,2,7,1,3], val = 5 | Output: []

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) return NULL;
        if(root->val == val) return root;
        if(val < root->val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
};