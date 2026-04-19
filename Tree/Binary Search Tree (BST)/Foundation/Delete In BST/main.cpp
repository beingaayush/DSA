// Delete Node in a BST:
// Goal: BST se node delete karna + BST property maintain rakhna

// Step 1: Search the value / key
// key < root → left
// key > root → right
// key == root → delete this node


// Step 2: Deletion Cases - here we have to tackle 3 cases

// 1. Leaf node (0 child)
// Direct delete
// return NULL

// 2. One child
// Node ko uske child se replace kar do
// return root->left or root->right

// 3. Two children (IMPORTANT)
// You cannot delete directly
// Replace value with:
// Inorder successor (smallest in right subtree / leftmost node in right subtree)
// Then delete that successor/predecessor node recursively

// (preferred)
// Steps:
// successor find karo
// root->val = successor->val
// successor ko recursively delete karo (right subtree me)
// Successor Find
// root->right jao
// phir leftmost node tak jao

// Flow Summary
// search → node mila
// case check:
// 0 child → NULL
// 1 child → return child
// 2 child → replace + delete successor


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