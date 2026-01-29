// inserting element at first, last, at any position

#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
int main()
{
    node *head = new node{10, new node{20, new node{30, nullptr}}};
    // insert at first
    node *n = new node{5, head};
    head = n;

    // insert at end
    // We walk till last node, then attach new node.
    node *t = head;
    while (t->next != nullptr)
    {
        t = t->next;
    }
    t->next = new node{40, nullptr};

    // insert at any posiiton
    node *t2 = head;
    while (t2->data != 10)
    { // stop at 10
        t2 = t2->next;
    }

    node *n2 = new node{15, t2->next};
    t2->next = n2;
}