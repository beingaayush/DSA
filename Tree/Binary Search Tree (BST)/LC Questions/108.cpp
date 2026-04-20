// Problem statement:
// Given an integer array nums where the elements are sorted in ascending order, convert it into a height-balanced binary search tree (BST).
// A height-balanced BST is defined as a binary tree in which the depth of the two subtrees of every node never differs by more than 1.

// Core idea:
// Pick the middle element as root to keep the tree balanced.
// Left half → build left subtree
// Right half → build right subtree
// Apply same logic recursively
// 👉 Sorted array + middle split = height-balanced BST

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val = x;
        left = right = NULL;
    }
};

class Solution{
public:
    TreeNode* solve(vector<int> &nums, int low, int high){
        // base Case
        if(low > high) return NULL;

        int mid = (low + high)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = solve(nums, low, mid - 1);
        root->right = solve(nums, mid + 1, high);
        return root;
    }

    TreeNode* sortedArrToBST(vector<int> &nums){
        return solve(nums, 0, nums.size()-1);
    }
};