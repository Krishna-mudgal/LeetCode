#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:

//     // void addToRoot(TreeNode *r, ListNode *t){
//     //     if(r == NULL) return ;

//     //     if(r -> val >= t -> val && r -> left == NULL) {
//     //         TreeNode *a = new TreeNode(t -> val);
//     //         r -> left = a;
//     //         return;
//     //     }
//     //     else if(r -> val >= t -> val && r -> left != NULL) addToRoot(r -> left, t);
//     //     else if(r -> val < t -> val && r -> right != NULL) addToRoot(r -> right, t);
//     //     else {
//     //         TreeNode *a = new TreeNode(t -> val);
//     //         r -> right = a;
//     //         return;
//     //     }
//     // }

//     TreeNode* addToRoot(ListNode *start, ListNode *end){
        
//         if(start == end) return NULL;

//         ListNode *slow = start;
//         ListNode *fast = start;

//         // finding middle 
//         while(fast != end && fast -> next != end){
//             slow = slow -> next;
//             if(fast -> next) fast = fast -> next -> next;
//         }   

//         TreeNode *node = new TreeNode(slow -> val);
//         node -> left = addToRoot(start, slow); // creating left subtree
//         node -> right = addToRoot(slow -> next, end); // creating right subtree

//         return node;
        
//     }

//     TreeNode* sortedListToBST(ListNode* head) {
//         if(head == NULL) return NULL;
//         if(head -> next == NULL) return new TreeNode(head -> val);

//         ListNode *slow = head;
//         ListNode *fast = head;

//         while(fast != NULL && fast -> next != NULL){
//             slow = slow -> next;
//             if(fast -> next) fast = fast -> next -> next;
//         }

//         TreeNode *root = new TreeNode(slow -> val);

//         root -> left = addToRoot(head , slow); // creating left sub tree and adding it to root
//         root -> right = addToRoot(slow -> next, NULL); // creating right subtree and adding it to root

//         return root;

//     }
// };