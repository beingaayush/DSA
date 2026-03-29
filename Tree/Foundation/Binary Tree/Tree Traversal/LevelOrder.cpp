// Traverse level by level (top → bottom)
// 👉 Left to right in each level
// 👉 Also called BFS (Breadth First Search)

// Tree:

//     1
//    / \
//   2   3
//  / \
// 4   5

// 👉 Output:- 1 2 3 4 5

// Key Idea:
// 👉 Recursion nahi
// 👉 Queue use hota hai
// Why? => Because you process nodes in FIFO order (level by level)

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
void levelOrder(Node* root){
    queue<Node*> q;

    q.push(root);
    q.push(NULL); //for printing on next line
    while(q.size() > 0){
        Node* curr = q.front();
        q.pop();


        cout << curr->data << " ";
        if(curr == NULL){
            if(!q.empty()){
                cout << endl;
                q.push(NULL);
                continue;
            }
            else{
                break;
            }
        }
        
        if(curr->left != NULL) q.push(curr->left);
        if(curr->right != NULL) q.push(curr->right);
    }
}

int main(){
    vector<int> sequence{1, 2, 3, 4, 5};
    Node* root = buildTree(sequence);

    levelOrder(root);
}