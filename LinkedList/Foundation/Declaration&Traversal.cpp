#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

int main() {
    // Declaration & creation
    node* head = new node{10, nullptr};
    head->next = new node{20, nullptr};
    head->next->next = new node{30, nullptr};

    // Single line declaration 
    node* head = new node{10, new node{20, new node{30, nullptr}}};
    
    // Traversal
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}


