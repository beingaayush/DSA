// Problem Statement:
// Given the root of a binary tree, return the inorder traversal of its nodes’ values.
// Inorder traversal = Left → Root → Right

// example:
//     1
//      \
//       2
//      /
//     3
   
// Step-by-step (Inorder = Left → Root → Right):
// Start at 1 → no left → visit 1
// Move to right (2)
// At 2 → go left → visit 3
// Back to 2 → visit 2   
// Output: [1, 3, 2]


#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
    public:
        vector<int> inorderTraversal(TreeNode* root){
            vector<int> ans;
            TreeNode* curr = root;

            while(curr != NULL){
                // if there's no left child
                if(curr->left == NULL){
                    ans.push_back(curr->val);  // directly visit & print
                    curr = curr->right;        // move to the right side
                }
                else{
                    // inorder predecessor (left subtree ka rightmost node)
                    TreeNode* IP = curr->left;
                    // move till the righmost node
                    while(IP->right != NULL && IP->right != curr){
                        IP = IP->right;
                    }

                    // if thread (connection) is not build
                    if(IP->right == NULL){
                        IP->right = curr;      // build temporary
                        curr = curr->left;    // explore left subtree
                    }
                    else{
                        IP->right = NULL;             // remove thread (restore tree)
                        ans.push_back(curr->val);
                        curr = curr->right;          // right side move
                    }
                }
            }
            return ans;
        }
};