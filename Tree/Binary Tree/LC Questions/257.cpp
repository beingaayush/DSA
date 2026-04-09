// Problem Statement:
// Given the root of a binary tree, return all root-to-leaf paths in any order.
// A leaf is a node with no children.

// Example:
//    1
//   / \
//  2   3
//   \
//    5

// output:  ["1->2->5", "1->3"]   

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
    public:
        void solve(TreeNode* root, string path, vector<string> &ans){
            if(root->left == NULL && root->right == NULL){
                ans.push_back(path);
                return;
            }

            //if root's left exists
            if(root->left){
                solve(root->left, path+"->"+to_string(root->left->val), ans);
            }
            //if root's right exists
            if(root->right){
                solve(root->right, path+"->"+to_string(root->right->val), ans);
            }
        }

        vector<string> binaryTreePaths(TreeNode* root){
            vector<string> ans;
            string path = to_string(root->val);
            
            solve(root, path, ans);
            return ans;
        }
};