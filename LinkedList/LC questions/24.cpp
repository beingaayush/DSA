// Problem Statement:-
// You are given the head of a linked list.
// Swap every two adjacent nodes in the list and return the modified list.
// Rules:
// You must swap the nodes themselves, not just their values.
// If the list has an odd number of nodes, the last node remains unchanged.

// Example :
// Input:
// 1 → 2 → 3 → 4
// Output:
// 2 → 1 → 4 → 3

// Note: iss solution me - prev always points to:
// 👉 Previous swapped pair ka second node after swap (which becomes the tail of that pair), 
// Usko next pair ke head se connect karna hota hai.

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
    public:
    ListNode* swapPairs(ListNode* head){
        //base case
        if(head == NULL || head->next == NULL) return head;
        
        ListNode* first = head;
        ListNode* sec = head->next;
        ListNode* prev = NULL;
        while(first != NULL || sec != NULL){
            ListNode* third = sec->next;
            sec->next = first;
            first->next = third;
            if(prev != NULL){
                prev->next = sec;
            }
            else{
                head = sec;
            }
            //updations
            prev = first;
            first = third;
            if(third != NULL){
                sec->next = third;
            }
            else{
                sec = NULL;
            }
        }
        return head;
    }
};