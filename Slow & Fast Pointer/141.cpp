// Problem Statement:-
// Given the head of a linked list, determine if the linked list has a cycle.
// A cycle exists if some node in the list can be reached again by continuously following the next pointer.
// 👉 Return true if there is a cycle, otherwise return false.
// You are not allowed to modify the linked list.



//  struct ListNode {
//       int val;
//       ListNode *next;
//      ListNode(int x) : val(x), next(NULL) {}
//   };

// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != nullptr && fast->next != nullptr){
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow == fast){
//                 return true;
//             }
//         }
//         return false;
//     }
// };