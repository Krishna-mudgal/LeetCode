#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/swap-nodes-in-pairs/description/s

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
//     ListNode* swapPairs(ListNode* head) {

//         if(!head) return NULL;
//         if(!head -> next ) return head;
        
//         ListNode *h = head -> next;

//         ListNode *l = head, *r = head -> next;
//         ListNode *prev = NULL;

//         while(r){
//             ListNode *t = r -> next;

//             r -> next = l;
//             l -> next = t;

//             if(prev) prev -> next = r;

//             prev = l;
//             if(l -> next) l = l -> next;
//             r = l -> next;
//         }

//         return h;
//     }
// };