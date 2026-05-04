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
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:
        TreeNode* helper(vector<int> &preorder, int &i, int bound){
            if(i >= preorder.size() || preorder[i] > bound){
                return NULL;
            }

            TreeNode* root = new TreeNode(preorder[i++]);
            root->left = helper(preorder, i, root->val);
            root->right = helper(preorder, i, bound);
            return root;
        }
        TreeNode* bstFromPreorder(vector<int> &preorder){
            int i = 0;
            return helper(preorder, i, INT_MAX);
        }
};