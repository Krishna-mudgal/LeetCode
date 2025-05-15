#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10

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
//     int gcd(ListNode *a, ListNode *b){
//         int x = a -> val, y = b -> val;

//         while(y != 0){ // euclid's algo
//             int temp = y;
//             y = x % y;
//             x = temp;
//         }

//         return x;
//     }
//     ListNode* insertGreatestCommonDivisors(ListNode* head) {

//         if(! head -> next) return head;

//         ListNode *t1 = head;
//         ListNode *t2 = head -> next;

//         while(t2 != NULL){
//             int x = gcd(t1, t2);
//             ListNode *hcf = new ListNode(x);
//             t1 -> next = hcf;
//             hcf -> next = t2;

//             t1 = hcf -> next;
//             t2 = t2 -> next;
//         }

//         return head;
//     }
// };