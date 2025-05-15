#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
//     public:
    
//         TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &idx, int lo, int hi){
//             if(lo > hi) return NULL;
//             if(lo == hi){
//                 TreeNode *t = new TreeNode(preorder[idx]);
//                 idx++;
//                 return t;
//             }
    
//             TreeNode *r = new TreeNode(preorder[idx]);
//             int idx_in_pre = -1;
//             for(int i = lo; i <= hi; i++){
//                 if(inorder[i] == r -> val) {
//                     idx_in_pre = i;
//                     break;
//                 }
//             }
    
//             idx++;
//             r -> left = build(preorder, inorder, idx, lo, idx_in_pre - 1);
//             r -> right = build(preorder, inorder, idx, idx_in_pre + 1, hi);
//             return r;
//         }
    
//         TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {  
//             int idx = 0;
//             int n = preorder.size();
//             return build(preorder, inorder, idx, 0, n - 1);
//         }
//     };