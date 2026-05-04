// Problem Statement:
// Given an array of integers preorder, which represents the preorder traversal of a Binary Search Tree (BST),
// construct and return the root of the BST.

// Example: 
// Input: preorder = [8,5,1,7,10,12]
// Output: [8,5,10,1,7,null,12]

// Core Idea:
// Preorder = Root → Left → Right
// BST rule = left < root < right
// Approach:
// > First element is always the root.
// > Maintain a bound (upper limit).
// > Traverse preorder once using index:
// > If current value > bound → stop (belongs to some parent’s right subtree).
// Otherwise:
// > Create node
// > Recursively build:
// > Left subtree with new bound = current node value
// > Right subtree with same bound

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
    public:
        
};