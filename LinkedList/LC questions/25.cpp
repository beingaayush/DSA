// Problem Statement:-
// You are given the head of a linked list and an integer k.
// Reverse the nodes of the list k at a time, and return the modified list.
// Rules:
// Divide the linked list into consecutive groups of size k.
// Reverse the nodes in each group.
// If the number of nodes in the last group is less than k, leave them unchanged.

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;};
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        //base case
        if(head == NULL || k == 1) return head;

        ListNode* temp = head;
        int count = 0;

        // Step 1: Check karo ki kam se kam k nodes available hain ya nahi
        while(count < k){
            if(temp == NULL) return head;   // agar k nodes nahi mile to same head return
            temp = temp->next;
            count++;
        }

        // Step 2: Remaining list ko recursively reverse karo
        // temp ab (k+1)th node pe hai
        ListNode* prevNode = reverseKGroup(temp, k);

        // Step 3: Current k nodes ko reverse karo
        temp = head;
        count = 0;

        while(count < k){
            ListNode* next = temp->next;   // next node store karo
            temp->next = prevNode;         // link reverse karo

            prevNode = temp;               // prevNode ko aage badhao
            temp = next;                   // temp ko next pe le jao
            count++;
        }
        return prevNode;
    }
};