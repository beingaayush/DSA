// Order = Left → Right → Root
//     1
//    / \
//   2   3
//  / \
// 4   5

// Postorder Output:- 4 5 2 3 1

// At every node:
// > Go left
// >Go right
// >Print node
// 👉 Root is processed last

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

//building tree using recursion
static int idx = -1;
Node* buildTree(vector<int> sequence){
    idx++;
    if(sequence[idx] == -1) return NULL;

    Node* root = new Node(sequence[idx]);
    root->left = buildTree(sequence);
    root->right = buildTree(sequence);

    return root;
}

//Traversal
void postOrder(Node* root){
    if(root == NULL) return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << endl;
}

int main(){
    vector<int> sequence{1, 2, 3, 4, 5};
    Node* root = buildTree(sequence);

    postOrder(root);
}