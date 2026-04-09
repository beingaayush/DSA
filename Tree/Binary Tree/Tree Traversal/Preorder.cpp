// Preorder = Root first
// Tree:
//     1
//    / \
//   2   3
//  / \
// 4   5

// Preorder output:- 1 2 4 5 3

// At every node:
// Print current node
// Go left
// Go right

#include <bits/stdc++.h>
using namespace std;

class Node{
public:    
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

//building tree
static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1) return NULL;
    
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);        //LEFT subtree
    root->right = buildTree(preorder);      //RIGHT subtree

    return root;
}

//Traversal
void preOrder(Node* root){
    if(root == NULL) return;

    cout << root->data;
    preOrder(root->left);
    preOrder(root->right);
}

int main (){
    vector<int> preorder = {1, 2, 3, 4, 5};
    Node* root = buildTree(preorder);

    preOrder(root);
    return;
}