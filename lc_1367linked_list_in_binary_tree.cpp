#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/linked-list-in-binary-tree/?envType=daily-question&envId=2024-09-07

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

// class Solution { // mene while lga kr dekha work ni kiya
// public:
//     bool check(ListNode *t, TreeNode *r){
//         if(t == NULL) return true; // if check krte krte ll ke end pr phuch gye to return true krdena
//         if(r == NULL) return false; // if check krte krte tree ke end pr phuch gye aur ll abhi tk ni mili to return false krdena

//         if(t -> val != r -> val) return false;

//         return check(t -> next, r -> left) || check(t -> next, r -> right); // l.s.t aur r.s.t m dekh kr aao jha bhi true aye true return krdena
//     }
//     void travel(ListNode *t, TreeNode *r, bool &flag){
//         if(r == NULL) return;

//         if(r -> val == t -> val) flag = check(t -> next, r -> left) || check(t -> next, r -> right); // head agr match hogya h to baki ki l.l, l.s.t aur r.s.t m check krke aao
//         if(flag == true) return;

//         travel(t, r -> left, flag);
//         travel(t, r -> right, flag);

//     }
//     bool isSubPath(ListNode* head, TreeNode* root) {
//         if(root == NULL) return false;

//         bool flag = false;
//         travel(head, root, flag);

//         return flag;
//     }   
// };