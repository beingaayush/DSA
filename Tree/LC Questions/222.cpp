// Problem Statement:
// Given the root of a complete binary tree, return the number of the nodes in the tree.

// remember:- Tree complete binary tree hai, matlab:
// Har level fully filled hota hai
// Last level left se fill hota hai (right side empty ho sakta hai)
// example:
//         1
//        / \
//       2   3
//      / \  /
//     4  5 6
//     output: 6 | (total 6 nodes)

// Core idea:
// calc all left nodes, right nodes then add them left + right + root(1)


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

class Solution{
    public:
        int countNodes(Node* root){
            if(root == NULL) return 0;
            int leftCnt = countNodes(root->left);
            int rightCnt = countNodes(root->right);
            return leftCnt + rightCnt + 1;
        }
};