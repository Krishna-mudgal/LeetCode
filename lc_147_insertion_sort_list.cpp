#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/insertion-sort-list/

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
// class Solution { // approach - 1
// public:
//     ListNode* insertionSortList(ListNode* head) {
//         vector<int> v;
//         ListNode *t = head;
        
//         while(t){
//             v.push_back(t -> val);
//             t = t -> next;
//         }

//         for(int i = 1; i < v.size(); i++){
//             int j = i;
//             while(j > 0 && v[j] < v[j - 1]){
//                 swap(v[j], v[j - 1]);
//                 j--;
//             }
//         }

//         t = head;
//         int i = 0;
//         while(t){
//             if(i < v.size()) t -> val = v[i];
//             i++;
//             t = t -> next;
//         }

//         return head;

//     }
// };

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
//     ListNode* insertionSortList(ListNode* head) { // approach - 2

//         ListNode *dummy = new ListNode(-1);
//         ListNode *td = dummy;
//         ListNode *p = head;

//         while(p){
//             ListNode *t = head;
//             int min_v = INT_MAX;
//             ListNode *mn = t;
//             while(t){
//                 if(min_v > t -> val) {
//                     min_v = t -> val;
//                     mn = t;
//                 }
//                 t = t -> next;
//             }

//             mn -> val = INT_MAX;
//             ListNode *t2 = new ListNode(min_v);

//             td -> next = t2;
//             td = t2;
//             p = p -> next;
//         }
        
//         return dummy -> next;
//     }
// };