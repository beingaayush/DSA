// Problem Statement:
// Given a root node of a Binary Search Tree (BST) and a key, delete the node with the given key in the BST.
// Return the root node reference of the BST (possibly updated).

// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node while maintaining the BST property.


#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
public:
    TreeNode* getInorderSuccessor(TreeNode* root){
        while(root != NULL && root->left != NULL){
            root = root->left;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root == NULL) return NULL;
        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){
            root->right = deleteNode(root->right, key);
        }
        else{
            // root == key
            if(root->left == NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }
            else if(root->right == NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            else{
                // 2 children
                TreeNode* IS = getInorderSuccessor(root->right);
                root->val = IS->val;
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};