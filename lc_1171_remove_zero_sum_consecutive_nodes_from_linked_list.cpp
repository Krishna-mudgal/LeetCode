#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/description/

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
//     ListNode* removeZeroSumSublists(ListNode* head) {
//         vector<int> v;
//         ListNode *t = head;
//         while(t){
//             v.push_back(t -> val);
//             t = t -> next;
//         }

//         unordered_map<int, int> m;
//         unordered_set<int> s;
//         m[v[0]] = 0;
//         if(v[0] == 0) {
//             s.insert(0);
//             m.erase(v[0]);
//         }
//         for(int i = 1; i < v.size(); i++){
//             v[i] += v[i - 1];
//             if(v[i] == 0){
//                 for(int j = 0; j <= i; j++) { // agr ith prefix sum 0 h to iska mtlv 0idx se lekar ab tk ke number ka sum 0 to insb ko bhi set m daal do
//                     s.insert(j);
//                     m.erase(v[j]);
//                 }
//             }
//             else if(m.find(v[i]) != m.end()){ // agr ith prefix sum phle kbhi dekha tha to iska mtlv phle jb dekha tha aur jb ab dekha h unke bich ka sum 0 h
//                 for(int j = m[v[i]] + 1; j <= i; j++) {
//                     s.insert(j);
//                     m.erase(v[j]);
//                 } // jis subaaray ka sum 0 h uske index set m daal do
//             }
//             m[v[i]] = i;
//         }

//         ListNode *dummy = new ListNode(-1);
//         t = dummy;
//         auto t2 = head;

//         for(int i = 0; i < v.size(); i++){
//             if(s.find(i) == s.end()){
//                 ListNode *temp = new ListNode(t2 -> val);
//                 t -> next = temp;
//                 t = temp;
//             }
//             t2 = t2 -> next;
//         }
        
//         return dummy -> next;
//     }
// };