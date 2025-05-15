#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {

//         if(!head || !head -> next) return head;

//         ListNode *dummy = new ListNode(-1);
//         dummy -> next = head;
//         ListNode *t = dummy -> next;
//         ListNode *prev = dummy;

//         while(t != NULL){
//             ListNode *t2 = t;
//             bool flag = false;
//             while(t2 && t2 -> next && t2 -> val == t2 -> next -> val){
//                 t2 = t2 -> next;
//                 flag = true;
//             }
//             if(t2 && flag) {
//                 t2 = t2 -> next;
//                 prev -> next = t2;
//                 t = t2;
//             }
//             else {
//                 prev = t;
//                 t = t -> next;
//             }
//         }

//         return dummy -> next;
//     }
// };