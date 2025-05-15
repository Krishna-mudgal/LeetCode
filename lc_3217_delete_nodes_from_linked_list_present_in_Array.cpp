#include <bits/stdc++.h>
using namespace std;

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

// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06
class ListNode{
    // already implemented in lc
public :
    int val;
    ListNode *next;

    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
    }
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) m[nums[i]]++;

        ListNode *temp = head;
        ListNode * prev = head;

        if(m.find(head -> val) != m.end()){
            while(temp != NULL){
                if(m.find(temp -> val) != m.end()) temp = temp -> next;
                else{
                    head = temp;
                    break;
                }
            }
        }
        prev = temp;
        if(temp) temp = temp -> next;
        while(temp){
            if(m.find(temp -> val) != m.end()){
                temp = temp -> next;
            }
            else{
                prev -> next = temp;
                prev = temp;
                temp = temp -> next;
            }
        }

        if(temp == NULL && prev != NULL) prev -> next = NULL;

        return head;
    }
};