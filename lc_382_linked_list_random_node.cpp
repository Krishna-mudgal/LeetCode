#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/linked-list-random-node/description/

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

//     vector<int> v;

//     Solution(ListNode* head) {
//         ListNode*t = head;
//         while(t){
//             v.push_back(t -> val);
//             t = t -> next;
//         }
//     }
    
//     int getRandom() {
//         int idx = rand() % (v.size());
//         // cout << rand() << endl;
//         return v[idx];
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */