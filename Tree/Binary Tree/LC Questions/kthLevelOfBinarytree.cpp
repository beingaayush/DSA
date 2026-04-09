// Problem Statement:
// Binary tree diya hai, ek integer k diya hai. Tumhe k-th level ke saare nodes return/print karne hain.
// Root = level 1
// Agar k exist nahi karta → empty return

// Core Idea:
// k ko distance from current node samajh
// Start me root se k steps niche jaana hai
// Har recursion me: k-- → ek level niche aa gaye
// Jab k == 1, matlab root se exactly k steps aa gaye → yehi nodes chahiye

#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    // tree definition...
    int val;
    TreeNode* left;
    TreeNode* right;
};
class Solution {
public:
    void solve(TreeNode* root, int k, vector<int> &ans){
        if(root == NULL) return;

        if(k == 1){
            ans.push_back(root->val);
            return;
        }

        solve(root->left, k - 1, ans);
        solve(root->right, k - 1, ans);
    }

    vector<int> kthLevel(TreeNode* root, int k) {
        vector<int> ans;
        solve(root, k, ans);
        return ans;
    }
};