// problem statement: calculate the sum of all the nodes

#include <bits/stdc++.h>
using namespace std;

// Definition of TreeNode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Function to calculate sum of all nodes
int sumNodes(TreeNode* root) {
    if(root == NULL) return 0;

    int leftSum = sumNodes(root->left);
    int rightSum = sumNodes(root->right);

    return leftSum + rightSum + root->val;
}

int main() {
    /*
        Example Tree:
              1
             / \
            2   3
           / \
          4   5

        Sum = 1+2+3+4+5 = 15
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Sum of nodes: " << sumNodes(root);

    return 0;
}