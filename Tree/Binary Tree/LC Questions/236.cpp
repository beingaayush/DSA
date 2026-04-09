// Problem Statement:
// Given a binary tree and two nodes p and q, find their lowest common ancestor.
// Lowest common ancestor = tree ka wo sabse neeche wala node jiske subtree me p aur q dono present ho.

// example:
//         3
//        / \
//       5   1
//      / \ / \
//     6  2 0  8
//       / \
//      7   4
  
// p = 5, q = 1
// ➝ LCA = 3
// p = 5, q = 4
// ➝ LCA = 5

// Reason:
// 3 ke niche 5 aur 1 dono aa rahe → LCA = 3
// 5 ke niche 4 already aa raha → LCA = 5     

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // Base case)
        if(root == NULL){
            return NULL;
        }

        // Agar current node hi p ya q hai → ye potential LCA ho sakta hai
        if(root->val == p->val || root->val == q->val){
            return root;
        }

        // Search for LCA in left subtree
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);

        // Search for LCA in right subtree
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // Case 1: dono side se non-null mila
        // matlab p aur q alag-alag subtree me mile → current node hi LCA hai
        if(leftLCA && rightLCA){
            return root;
        }

        // Case 2: sirf left me mila → wahi LCA hai
        else if(leftLCA != NULL) return leftLCA;

        // Case 3: sirf right me mila → wahi LCA hai
        else return rightLCA;
    }
};