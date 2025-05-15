#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/split-linked-list-in-parts/?envType=daily-question&envId=2024-09-08


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
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         vector<ListNode *> ans;

//         int n = 0;
//         ListNode *t = head;

//         while(t){
//             n++;
//             t = t -> next;
//         }
//         int size = n/k;
//         int curr_size = 1;
//         int extra = n % k;

//         t = head;
//         ListNode *t2 = t;

//         while(t){
//             if(extra > 0){
//                 while(t && curr_size < size + 1){
//                     t = t -> next;
//                     curr_size++;
//                 }
//                 if(curr_size == size + 1){
//                     ans.push_back(t2);
//                     k--;
//                     t2 = t;
//                     if(t) t = t -> next;
//                     t2 -> next = NULL;
//                     t2 = t;
//                     extra--;
//                     curr_size = 1;
//                 }
//             }
//             else{
//                 while(t && curr_size < size){
//                     t = t -> next;
//                     curr_size++;
//                 }
//                 if(curr_size == size){
//                     ans.push_back(t2);
//                     k--;
//                     t2 = t;
//                     if(t) t = t -> next;
//                     t2 -> next = NULL;
//                     t2 = t;
//                     curr_size = 1;
//                 }
//             }
//         }

//         while(k > 0){
//             ans.push_back({});
//             k--;
//         }

//         return ans;

//     }
// };  

// 2nd approach

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
//     vector<ListNode*> splitListToParts(ListNode* head, int k) {
//         ListNode *temp = head;
//         vector<ListNode *> ans;
//         int n = 0;
//         while(temp){
//             n++;
//             temp = temp -> next;
//         }
//         int size = n/k;
//         int current_size = 0;
//         int x = n%k;
        
//         temp = head;
//         ListNode *c = new ListNode(-1);
//         ListNode *tc = c;
//         while(x > 0){
//             if(current_size == size+1){
//                 tc -> next = NULL;
//                 ans.push_back(c -> next);
//                 k--;
//                 tc = c;
//                 current_size = 0;
//                 x--;
//             }
//             else{
//                 tc -> next = temp;
//                 tc = temp;
//                 temp = temp -> next;
//                 current_size++;
//             }
//         }
//         current_size = 0;
//         while(temp){
//             if(current_size == size){
//                 tc -> next = NULL;
//                 ans.push_back(c -> next);
//                 k--;
//                 tc = c;
//                 current_size = 0;
//             }
//             else{
//                 tc -> next = temp;
//                 tc = temp;
//                 temp = temp -> next;
//                 current_size++;
//             }
//         }

//         // chuki temp null hote hi loop toot jyga to last wala add ni ho pyga 
//         tc -> next = NULL;
//         ans.push_back(c -> next);
//         k--;

//         while(k > 0){
//             ans.push_back(NULL);
//             k--;
//         }



//         return ans;
//     }
// };