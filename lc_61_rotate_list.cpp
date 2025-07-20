#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * 
 */

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) { // T.C. = O(n) +  O(n - k) = O(n)
        int n = 0;
        ListNode *temp = head;
        ListNode *end = head;

        if(k == 0 || !head) return head;

        while(temp){ // O(n)
            n++;
            end = temp;
            temp = temp -> next;
        }
        
        k %= n;
        n--;

        if(k == 0 || !head) return head;

        int i = 0;
        temp = head;
        ListNode * newHead = NULL;
        while(i < n - k){ // O(n- k)
            temp = temp -> next;
            i++;
        }

        newHead = temp -> next;
        end -> next = head;
        temp -> next = NULL;

        return newHead;
    }
};