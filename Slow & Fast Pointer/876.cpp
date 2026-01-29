// Problem statement:-
// find the Middle of linked List


// class Solution {
// public:
//     ListNode* middleNode(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != nullptr && fast->next != nullptr){
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }
// };