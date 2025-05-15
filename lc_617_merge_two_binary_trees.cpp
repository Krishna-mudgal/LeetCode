#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/merge-two-binary-trees/description/

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

//     void helper(TreeNode *r1, TreeNode *r2){

//         if(r2 && r1) r1 -> val += r2 -> val;

//         if(r1 -> left && r2 -> left) helper(r1 -> left, r2 -> left);
//         else if(!r1 -> left && r2 -> left) r1 -> left = r2 -> left;

//         if(r1 -> right && r2 -> right) helper(r1 -> right, r2 -> right);
//         else if(!r1 -> right && r2 -> right) r1 -> right = r2 -> right;
        

//     }

//     TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
//         if(!root1) return root2;
//         else if(!root2) return root1;
        
//         helper(root1, root2);
//         return root1;
//     }
// };