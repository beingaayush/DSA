// Deleting element from first, last, from any position

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};

int main(){
    node* head = new node{10, new node{20, new node{30, new node{40, nullptr}}}};

    //del 1st node/element
    node* temp = head;         //store old head
    head = head->next;      //move head one forward
    delete temp;              //delete old/temp head


    //del last element
    node* t = head;
    // go to second last node
    while (t->next->next != nullptr) {
        t = t->next;
    }
    delete t->next;      // delete last node
    t->next = nullptr;   // fix link

}