// Problem statement:
// Given the root of a binary tree, flatten the tree into a linked list in-place.

// The linked list should use the same TreeNode structure.
// The right child pointer should point to the next node.
// The left child pointer should always be NULL.
// The order of nodes should follow preorder traversal (Root → Left → Right).

// Example:
//     1
//    / \
//   2   5
//  / \   \
// 3   4   6
// Output: 1 -> 2 -> 3 -> 4 -> 5 -> 6

// Core idea:
// Core samajh:
// Hum reverse se list bana rahe hain (last node se start)
// Orde: Right → Left → Root
// Isliye final output automatically Root → Left → Right (preorder) ban jaata hai


#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
    public:
    TreeNode* nextRight = NULL;
    
    void flatten(TreeNode* root) {
        if(root == NULL) return;

        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};