#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/binary-tree-pruning/description/

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

//     bool check(TreeNode *r){
//         if(!r) return false;
//         if(r -> val == 1) return true;
//         return (check(r -> left) || check(r -> right));
//     }

//     TreeNode* pruneTree(TreeNode* root) {
//         if(!check(root)) return NULL;
        
//         if(!check(root -> left)) root -> left = NULL;
//         if(!check(root -> right)) root -> right = NULL;

//         if(root -> left) pruneTree(root -> left);
//         if(root -> right) pruneTree(root -> right);

//         return root;
//     }
// };