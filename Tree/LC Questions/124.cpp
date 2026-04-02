// Problem Statemen:
// Given the root of a binary tree, return the maximum path sum.
// A path is any sequence of nodes connected by edges
// The path does not need to pass through the root
// Each node can appear at most once in the path
// Path must contain at least one node
// 👉 Return the maximum possible sum of values along any such path.

// Tree me kisi bhi path ka maximum sum nikalna hai
// (path = continuous nodes, root se start hona zaroori nahi)
// eg:
//       -10
//       /  \
//      9   20
//          / \
//         15  7

// 👉 Best path: 15 → 20 → 7
// 👉 Sum = 15 + 20 + 7 = 42
// ✔️ Answer = 42

// Core Idea:
// Har node pe:- left aur right ka max path lo
// agar negative ho → ignore (0 le lo)
// current node ko center maan ke
// left + right + node se global max update karo
// parent ko return karo → node + max(left, right)

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
public:
    int solve(TreeNode* root, int &maxi){
        if(root == NULL) return 0;

        // taking zero for handling -ve values
        int left = max(0, solve(root->left, maxi));
        int right = max(0, solve(root->right, maxi));
        maxi = max(maxi, left + right + root->val);

        return max(left, right) + root->val;
    }
    int maxPathSum(TreeNode* root){
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};