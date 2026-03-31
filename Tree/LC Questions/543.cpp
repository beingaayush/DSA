// Problem Statement:
// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
// This path may or may not pass through the root.
// The length of a path between two nodes is represented by the number of edges between them.

// Core idea:
// Diameter at any node = left subtree height + right subtree height
// So for every node:- Find height of left subtree and Find height of right subtree
// Update max diameter = left + right


#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution{
    public:
        int height(TreeNode* root){
            if(root == NULL) return 0;

            int leftHeight = height(root->left);
            int rightHeight = height(root->right);

            return max(leftHeight, rightHeight) + 1;
        }

        int diameterOfBinaryTree(TreeNode* root){
            if(root == NULL) return 0;

            int leftDiameter = diameterOfBinaryTree(root->left);
            int rightDiameter = diameterOfBinaryTree(root->right);
            int currDiameter = height(root->left) + height(root->right);

            return max(currDiameter, max(leftDiameter, rightDiameter)); // Diameter is counted in edges, not nodes So no +1 while updating diameter
        }
};