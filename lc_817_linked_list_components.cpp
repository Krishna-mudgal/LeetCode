#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-components/

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
//     int numComponents(ListNode* head, vector<int>& nums) {
//         int n = nums.size();

//         unordered_set<int> st;
//         for(int i : nums) st.insert(i);

//         auto t = head;
//         int ans = 0;
//         bool flag = false;
//         while(t){
//             if(st.find(t -> val) == st.end()) {
//                 if(flag) ans++;
//                 flag = false;
//             }
//             else flag = true;

//             t =  t -> next;
//         }

//         if(flag) ans++;

//         return ans;
//     }
// };