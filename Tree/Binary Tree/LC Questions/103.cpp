// Problem Statement:
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
// First level → left to right
// Next level → right to left
// Alternate this pattern for every level
// Return the result as a list of lists.


#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution{
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode* root){
            vector<vector<int>> result;
            if(root == NULL) return result;
            bool leftToRight = true;    // direction control (L→R ya R→L) | flag

            queue<TreeNode*> q;
            q.push(root);  //start traversal from root

            while(!q.empty()){
                int size = q.size();
                vector<int> row(size);  //To store the result of one level

                for(int i=0; i<size; i++){
                    TreeNode* node = q.front();
                    q.pop();

                    // agar L→R hai to normal index
                    // agar R→L hai to reverse index
                    int index = (leftToRight) ? i: (size - 1 - i);
                    row[index] = node->val;   //store the value at correct position

                    if(node->left){
                        q.push(node->left);    //next level ke liye left add
                    }
                    if(node->right){
                        q.push(node->right);  //next level ke liye right add
                    }
                }
                leftToRight = !leftToRight;    //flip direction
                result.push_back(row);
            }
            return result;
        }  
};