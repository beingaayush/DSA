// Problem Statement:
// Given the root of a BST and a value val, insert val into the tree such that the BST property is maintained.
// Return the root of the updated BST.
// (New node will always be inserted as a leaf.)

// Core Idea:
// > Start from root
// > Compare val with current node
// > If val < node → go left
// > If val > node → go right
// > Keep moving until you hit NULL
// > Insert new node at that position


#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
        TreeNode* insertIntoBST(TreeNode* root, int val){
            // Case 1: Found empty position → insert here
            if(root == NULL){
                return new TreeNode(val);    //create new node and return
            }

            // Case 2: Value is smaller → go to left subtree
            if(val < root->val){
                root->left = insertIntoBST(root->left, val);
            }
            // Case 3: Value is larger → go to right subtree
            else{
                root->right = insertIntoBST(root->right, val);
            }

            return root;   // Return the unchanged root (to maintain tree structure)
        }
};