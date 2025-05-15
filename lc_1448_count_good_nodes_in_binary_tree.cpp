#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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

//     void travel(TreeNode *r, int &ans, int mx){
//         if(!r) return;

//         mx = max(mx, r -> val);
//         if(mx == r -> val) ans++;

//         travel(r -> left, ans, mx);
//         travel(r -> right, ans, mx);
//     }

//     int goodNodes(TreeNode* root) {
//         int ans = 0;
//         int mx = root -> val;
//         travel(root, ans, mx);
//         return ans;
//     }
// };