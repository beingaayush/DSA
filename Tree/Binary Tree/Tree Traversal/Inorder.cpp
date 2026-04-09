// Order = Left → Root → Right
//     1
//    / \
//   2   3
//  / \
// 4   5

// Inorder Output:- 4 2 5 1 3

// At every node:
// > Go left
// > Print current node
// > Go right

// In Binary Search Tree (BST):-- Inorder traversal gives sorted output

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

//traversal
void inorder(Node* root){
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main(){
    //building the tree manually
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inorder(root);
}