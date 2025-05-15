#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/

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
//     ListNode* deleteMiddle(ListNode* head) {
//         if(!head -> next) return NULL;
        
//         ListNode *slow = head;
//         ListNode *fast = head;
//         ListNode *prev = head;

//         while(fast && fast -> next){
//             if(!(fast -> next)){
//                 prev = slow;
//                 slow = slow -> next;
//                 break;
//             }
//             prev = slow;
//             slow = slow -> next;
//             fast = fast -> next -> next;
//         }

//         prev -> next = slow -> next;

//         return head;
//     }
// };