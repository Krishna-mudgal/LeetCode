#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-tilt/description/

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

//     int helper(TreeNode *r){
//         if(r == NULL) return 0;

//         if(!r -> left && !r -> right) return r -> val; // leaf node

//         return r -> val + helper(r -> left) + helper(r -> right);

//     }

//     int findTilt(TreeNode* root) {
//         if(root == NULL) return 0;

//         return abs(helper(root -> left) - helper(root -> right)) + findTilt(root -> left) + findTilt(root -> right);

//     }
// };