#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/sum-root-to-leaf-numbers/description/

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
//     void helper(TreeNode *r, int &ans, string s){
//         if(r == NULL) return ;

//         if(!r -> left && !r -> right) {
//             s += (char)(r -> val + '0'); // adding leaf node
//             ans += stoi(s);
//             return;
//         }

//         helper(r -> left, ans, s + (char)(r -> val + '0'));
//         helper(r -> right, ans, s + (char)(r -> val + '0'));

//     }
//     int sumNumbers(TreeNode* root) {
//         int ans = 0;
//         helper(root, ans, "");

//         return ans;
//     }
// };