#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/description/

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
// class Solution { // approach 1
// public:
//     void helper(TreeNode *r, unordered_set<int> &s){
//         if(r == NULL) return ;

//         s.insert(r -> val);

//         helper(r -> left, s);
//         helper(r -> right, s);

//     }
//     int findSecondMinimumValue(TreeNode* root) {
//         unordered_set<int> s;
//         helper(root, s);

//         if(s.size() == 1) return -1;

//         int mn = INT_MAX, s_mn = INT_MAX;
//         for(int x : s){
//             if(x < mn) {
//                 s_mn = mn;
//                 mn = x;
//             }

//             if(x > mn && x < s_mn) s_mn = x;
//         }

//         return s_mn;

//     }
// };

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution { // approach - 2
// public:
//     void helper(TreeNode *r, long &mn, long &s_mn){
//         if(r == NULL) return;

//         if(r -> val < mn){
//             s_mn = mn;
//             mn = r -> val;
//         }
//         if(r -> val > mn && r -> val < s_mn) s_mn = r -> val;

//         helper(r -> left, mn, s_mn);
//         helper(r -> right, mn, s_mn);

//     }
//     int findSecondMinimumValue(TreeNode* root) {
//         long mn = LONG_MAX;
//         long s_mn = LONG_MAX;

//         helper(root, mn, s_mn);

//         return (s_mn == LONG_MAX) ? -1 : s_mn;

//     }
// };