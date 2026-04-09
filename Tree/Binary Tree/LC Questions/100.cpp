// Problem Statement:
// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


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
        bool isSameTree(TreeNode* p, TreeNode* q){
            //base case (if both root is NULL OR either one of them is NULL)
            if(p == NULL || q == NULL){
                return p == q;
            }

            bool isLeftSame = isSameTree(p->left, q->left);        //return true if both tree's left subtree identical
            bool isRightSame = isSameTree(p->right, q->right);    //return true if both tree's right subtree identical

            return isLeftSame && isRightSame && p->val == q->val;  //return true when leftsubtree same, rightsubtree same and both Tree's root->val are same are same
        }
};
