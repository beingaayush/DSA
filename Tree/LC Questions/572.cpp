// Problem Statement:
// Given the roots of two binary trees root and subRoot
// return true if there is a subtree of root with the same structure and node values of subRoot and false otherwise.

// A subtree of a binary tree tree is a tree that consists of a node in tree and all of this node's descendants.
// The tree tree could also be considered as a subtree of itself.

// Main tree:
//         3
//        / \
//       4   5
//      / \
//     1   2

// SubTree:
//       4
//      / \
//     1   2    

// Core idea:
// Har node of root ko possible starting point maano
// Har node pe check karo:- “Kya yahan se pura tree subRoot ke exact same hai?” | Ye check = LC 100 (Same Tree / identical check)
// Har node pe:
// isIdentical(root, subRoot) call karo
// Agar kahin bhi match mil gaya → true | Nahi mila → false

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
        // Check if two trees are exactly identical (LC 100 logic)
        bool isIdentical(TreeNode* p, TreeNode* q){
            if(p == NULL || q == NULL) return p == q;

            return p->val == q->val && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
        }

        bool isSubtree(TreeNode* root, TreeNode* subRoot){
            //base case
            if(root == NULL || subRoot == NULL) root == subRoot;
           
            if(isIdentical(root, subRoot)) return true;  // Check if current node can be starting point
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);  // Otherwise, search in left OR right subtree
        }
};