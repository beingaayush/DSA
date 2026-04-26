// Problem Statement:
// Given the root of a Binary Search Tree (BST), return the minimum difference between the values of any two different nodes in the tree.

// Core idea:
// 👉 In a BST, inorder traversal gives sorted values.
// 👉 Minimum difference will always be between two adjacent elements in this sorted order.
// # Logic:
// > Traverse inorder
// > Keep track of previous node (prev)
// > At each node → compute current - prev
// > Maintain global minimum
// That’s it. No need to compare non-adjacent nodes because sorted order guarantees they won’t give a smaller difference.

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
    public:
        TreeNode* prev = NULL;
        int minDiffInBST(TreeNode* root){
            if(root == NULL) return INT_MAX;
            int ans = INT_MAX;

            // Inorder Traversing

            if(root->left){
                int leftMin = minDiffInBST(root->left);
                ans = min(ans, leftMin);
            }

            if(prev != NULL){
                ans = min(ans, root->val - prev->val);
            }
            prev = root;

            if(root->right){
                int rightMin = minDiffInBST(root->right);
                ans = min(ans, rightMin);
            }
            return ans;
        }
};