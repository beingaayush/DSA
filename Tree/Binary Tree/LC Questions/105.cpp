// Problem Statement:
// Given two integer arrays:
// preorder → represents the preorder traversal of a binary tree
// inorder → represents the inorder traversal of the same tree
// Your task is to construct and return the binary tree.

// Example: preorder = [3, 9, 20, 15, 7]  |  inorder  = [9, 3, 15, 20, 7]
// Step 1: First Root
// preIdx = 0 → preorder[0] = 3 | So, root = 3
// Find 3 in inorder:
// [9, 3, 15, 20, 7]
//      ↑

// 👉 Left part = [9]
// 👉 Right part = [15, 20, 7]

// Step 2: Build Left Subtree of 3
// preIdx = 1 → preorder[1] = 9
// So, left child = 9

// Find 9 in inorder:
// [9]
//  ↑

// 👉 No left, no right → leaf node

// Step 3: Build Right Subtree of 3
// preIdx = 2 → preorder[2] = 20
// So, right child = 20

// Find 20 in inorder:
// [15, 20, 7]
//       ↑

// 👉 Left part = [15]
// 👉 Right part = [7]

// Step 4: Left of 20
// preIdx = 3 → preorder[3] = 15
// Leaf node
// Step 5: Right of 20
// preIdx = 4 → preorder[4] = 7
// Leaf node

//Final Tree: 
    //     3
    //    / \
    //   9   20
    //      /  \
    //     15   7

// ---------------------------------------------------------------------------------------------------------    
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

class Solution{
    public:
        int search(vector<int> &inorder, int left, int right, int val){
            for(int i=left; i<=right; i++){
                if(inorder[i] == val) return i;
            }

            return -1;
        }

        TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &preIdx, int left, int right){
            if(left > right) return NULL;

            // Pick root from preorder
            TreeNode* root = new TreeNode(preorder[preIdx]);

            int inIdx = search(inorder, left, right, root->val);  // Pick root from inorder
            preIdx++;

            root->left = solve(preorder, inorder, preIdx, left, inIdx - 1);     //Build left SUbtree
            root->right = solve(preorder, inorder, preIdx, inIdx + 1, right);   //Build right SUbtree

            return root;
        }

        TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
            int preIdx = 0;
            return solve(preorder, inorder, preIdx, 0, inorder.size() - 1);
        }
};