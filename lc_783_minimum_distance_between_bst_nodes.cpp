#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

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
    
//     void helper2(TreeNode *r1, TreeNode *r2, int &ans){
//         if(!r2) return;

//         if(r1 -> val != r2 -> val) ans = min(ans, abs(r1 -> val - r2 -> val));

//         if(r2 -> left) helper2(r1, r2 -> left, ans);
//         if(r2 -> right) helper2(r1, r2 -> right, ans);
//     }

//     void helper1(TreeNode *r, TreeNode *root, int &ans){
//         if(!r) return;

//         helper2(r, root, ans);

//         if(r -> left) helper1(r -> left, root, ans);
//         if(r -> right) helper1(r -> right, root, ans);
//     }

//     int minDiffInBST(TreeNode* root) {
//         int ans = INT_MAX;
//         helper1(root, root, ans);
//         return ans;
//     }
// };

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
// class Solution { // more optimized then previous
// public:
    
//     void helper2(TreeNode *r1, TreeNode *r2, int &ans){
//         if(!r2) return;

//         if(r1 -> val != r2 -> val) ans = min(ans, abs(r1 -> val - r2 -> val));

//         if(r2 -> left) helper2(r1, r2 -> left, ans);
//         if(r2 -> right) helper2(r1, r2 -> right, ans);
//     }

//     void helper1(TreeNode *r, int &ans){
//         if(!r) return;

//         helper2(r, r, ans);

//         if(r -> left) helper1(r -> left, ans);
//         if(r -> right) helper1(r -> right, ans);
//     }

//     int minDiffInBST(TreeNode* root) {
//         int ans = INT_MAX;
//         helper1(root, ans);
//         return ans;
//     }
// };