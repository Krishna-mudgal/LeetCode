#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/?envType=daily-question&envId=2025-02-23

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
        
//         TreeNode *build(vector<int> &preorder, vector<int> &postorder, int &idx, int lo, int hi){
//             if(lo > hi) return NULL;
//             if(lo == hi){
//                 TreeNode *t = new TreeNode(preorder[idx]);
//                 idx++;
//                 return t;
//             }
    
//             TreeNode *r = new TreeNode(preorder[idx]);
//             int left_val = preorder[idx + 1];
//             int left_idx_in_post = -1;
    
//             for(int i = lo; i <= hi; i++){
//                 if(postorder[i] == left_val){
//                     left_idx_in_post = i;
//                     break;
//                 }
//             }
    
//             idx++;
//             r -> left = build(preorder, postorder, idx, lo, left_idx_in_post);
//             r -> right = build(preorder, postorder, idx, left_idx_in_post + 1, hi - 1);
    
//             return r;
//         }
    
//         TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
//             int n = preorder.size();
//             int idx = 0;
//             return build(preorder, postorder, idx, 0, n - 1);
//         }
//     };