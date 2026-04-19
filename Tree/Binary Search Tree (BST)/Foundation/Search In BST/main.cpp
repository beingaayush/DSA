
#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
};

bool search(TreeNode* root, int key) {
    if (root == NULL) return false;

    if (root->data == key) return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}