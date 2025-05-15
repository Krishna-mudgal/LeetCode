#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/remove-linked-list-elements/



 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!(head) || (!(head -> next) && head -> val == val)) return NULL;
        if(head -> next == NULL && head -> val != val) return head;

        while(head && head -> val == val){
            head = head -> next;
        }

        if(head == NULL) return NULL;

        ListNode *temp = head -> next;
        ListNode *prev = head;

        while(temp != NULL){
            if(temp -> val == val){
                prev -> next  = temp -> next;
                temp = prev -> next;
            }
            else{
                prev = temp;
                temp = temp -> next;
            }
        }

        return head;
    }
};