// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

#include <bits/stdc++.h>
using namespace std;
struct Node{
 int data;
 Node* left;
 Node* right;
 Node(int val){
    data = val;
    left = right = NULL;
 }
};

class solution{
    public:
        int maxDepth(Node* root){
            if(root == NULL) return 0;
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);

            return max(leftDepth, rightDepth) + 1;
        }
};
